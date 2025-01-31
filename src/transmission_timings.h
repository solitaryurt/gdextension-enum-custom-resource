#pragma once

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/vector2.hpp>

namespace godot {

class TransmissionTimings : public Resource {
    GDCLASS(TransmissionTimings, Resource)

private:
    Array points;

protected:
    static void _bind_methods();

public:
    TransmissionTimings();
    ~TransmissionTimings();

    void add_point(const Vector2 &point);
    void remove_point(int index);
    void clear_points();

    Array get_points() const;
    void set_points(const Array &p_points);
};

}
