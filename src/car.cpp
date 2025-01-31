#include "car.h"
#include "macros.h"

using namespace godot;

void Car::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_brand", "brand"), &Car::set_brand);
    ClassDB::bind_method(D_METHOD("get_brand"), &Car::get_brand);
    ClassDB::bind_method(D_METHOD("set_year", "year"), &Car::set_year);
    ClassDB::bind_method(D_METHOD("get_year"), &Car::get_year);
    ClassDB::bind_method(D_METHOD("set_engine_type", "engine_type"), &Car::set_engine_type);
    ClassDB::bind_method(D_METHOD("get_engine_type"), &Car::get_engine_type);
    ClassDB::bind_method(D_METHOD("set_transmission_type", "transmission_type"), &Car::set_transmission_type);
    ClassDB::bind_method(D_METHOD("get_transmission_type"), &Car::get_transmission_type);
    ClassDB::bind_method(D_METHOD("set_transmission_timings", "transmission_timings"), &Car::set_transmission_timings);
    ClassDB::bind_method(D_METHOD("get_transmission_timings"), &Car::get_transmission_timings);
    ClassDB::bind_method(D_METHOD("set_msrp", "msrp"), &Car::set_msrp);
    ClassDB::bind_method(D_METHOD("get_msrp"), &Car::get_msrp);
    ClassDB::bind_method(D_METHOD("set_zero_to_sixty", "zero_to_sixty"), &Car::set_zero_to_sixty);
    ClassDB::bind_method(D_METHOD("get_zero_to_sixty"), &Car::get_zero_to_sixty);
    ClassDB::bind_method(D_METHOD("set_top_speed", "top_speed"), &Car::set_top_speed);
    ClassDB::bind_method(D_METHOD("get_top_speed"), &Car::get_top_speed);
    ClassDB::bind_method(D_METHOD("set_scene", "scene"), &Car::set_scene);
    ClassDB::bind_method(D_METHOD("get_scene"), &Car::get_scene);
    ClassDB::bind_method(D_METHOD("set_image", "image"), &Car::set_image);
    ClassDB::bind_method(D_METHOD("get_image"), &Car::get_image);

    ADD_PROPERTY(PropertyInfo(Variant::STRING, "brand"), "set_brand", "get_brand");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "year"), "set_year", "get_year");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "engine_type", PROPERTY_HINT_ENUM, ENUM_TO_STRING(EngineType, ENGINE_TYPE_COUNT).c_str()), "set_engine_type", "get_engine_type");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "transmission_type", PROPERTY_HINT_ENUM, ENUM_TO_STRING(TransmissionType, TRANSMISSION_TYPE_COUNT).c_str()), "set_transmission_type", "get_transmission_type");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "transmission_timings", PROPERTY_HINT_RESOURCE_TYPE, "TransmissionTimings"), "set_transmission_timings", "get_transmission_timings");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "msrp", PROPERTY_HINT_RANGE, "0,1000000,1"), "set_msrp", "get_msrp");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "zero_to_sixty", PROPERTY_HINT_RANGE, "0,10,1"), "set_zero_to_sixty", "get_zero_to_sixty");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "top_speed", PROPERTY_HINT_RANGE, "0,300,1"), "set_top_speed", "get_top_speed");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "scene", PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"), "set_scene", "get_scene");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "image", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_image", "get_image");
    
    BIND_ENUM_CONSTANT(TRANSMISSION_TYPE_MANUAL);
    BIND_ENUM_CONSTANT(TRANSMISSION_TYPE_AUTOMATIC);
    BIND_ENUM_CONSTANT(TRANSMISSION_TYPE_CVT);
    BIND_ENUM_CONSTANT(TRANSMISSION_TYPE_DUAL_CLUTCH);

    BIND_ENUM_CONSTANT(ENGINE_TYPE_GASOLINE);
    BIND_ENUM_CONSTANT(ENGINE_TYPE_DIESEL);
    BIND_ENUM_CONSTANT(ENGINE_TYPE_ELECTRIC);
    BIND_ENUM_CONSTANT(ENGINE_TYPE_HYBRID);
    BIND_ENUM_CONSTANT(ENGINE_TYPE_HYDROGEN);
}
