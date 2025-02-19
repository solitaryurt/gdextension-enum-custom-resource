extends ResourceTablesCellEditor

const TablesPluginSettingsClass := preload("res://addons/resources_spreadsheet_view/settings_grid.gd")

var previewer : EditorResourcePreview


func can_edit_value(value, type, property_hint, column_index) -> bool:
	return type == TYPE_OBJECT


func create_cell(caller : Control) -> Control:
	if previewer == null:
		previewer = caller.editor_plugin.get_editor_interface().get_resource_previewer()

	var node = load(CELL_SCENE_DIR + "resource.tscn").instantiate()
	return node


func set_value(node : Control, value):
	var preview_node := node.get_node("Box/Tex")
	var label_node := node.get_node("Box/Label")
	if value == null:
		preview_node.visible = false
		label_node.text = "[empty]"
		node.editor_description = ""

	if !value is Resource: return
	
	node.editor_description = value.resource_path
	if value.has_method(&"_to_string"):
		label_node.text = value._to_string() + "\n"

	if value.resource_name == "":
		label_node.text = "[" + value.resource_path.get_file() + "]"

	else:
		label_node.text = value.resource_name

	if value is Texture:
		preview_node.visible = true
		preview_node.texture = value

	else:
		preview_node.visible = false
		previewer.queue_resource_preview(value.resource_path, self, &"_on_preview_loaded", node)
		
	preview_node.custom_minimum_size = Vector2.ONE * ProjectSettings.get_setting(
		TablesPluginSettingsClass.PREFIX + "resource_preview_size"
	)


func set_color(node : Control, color : Color):
	node.get_node("Back").modulate = color * 0.6 if node.editor_description == "" else color


func is_text():
	return false


func _on_preview_loaded(path : String, preview : Texture, thumbnail_preview : Texture, node):
	# Abort if the node has been deleted since.
	if is_instance_valid(node):
		node.get_node("Box/Tex").visible = true
		node.get_node("Box/Tex").texture = preview
