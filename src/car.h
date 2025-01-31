#ifndef CAR_H
#define CAR_H

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "transmission_timings.h"

using namespace godot;

enum TransmissionType {
    TRANSMISSION_TYPE_MANUAL,
    TRANSMISSION_TYPE_AUTOMATIC,
    TRANSMISSION_TYPE_CVT,
    TRANSMISSION_TYPE_DUAL_CLUTCH,
    TRANSMISSION_TYPE_COUNT
};

enum EngineType {
    ENGINE_TYPE_GASOLINE,
    ENGINE_TYPE_DIESEL,
    ENGINE_TYPE_ELECTRIC,
    ENGINE_TYPE_HYBRID,
    ENGINE_TYPE_HYDROGEN,
    ENGINE_TYPE_COUNT
};

class Car : public Resource {
    GDCLASS(Car, Resource)

private:
    String brand;
    int year;
    EngineType engine_type;
    TransmissionType transmission_type;
    Ref<TransmissionTimings> transmission_timings;

    float msrp;
    float zero_to_sixty;
    float top_speed;

    Ref<PackedScene> scene;
    Ref<Texture2D> image;

protected:
    static void _bind_methods();

public:
    Car() = default;
    ~Car() = default;

    void set_brand(const String& p_brand) { brand = p_brand; }
    String get_brand() const { return brand; }
    void set_year(int p_year) { year = p_year; }
    int get_year() const { return year; }
    void set_engine_type(EngineType p_type) { engine_type = p_type; }
    EngineType get_engine_type() const { return engine_type; }
    void set_transmission_type(TransmissionType p_type) { transmission_type = p_type; }
    TransmissionType get_transmission_type() const { return transmission_type; }
    void set_transmission_timings(Ref<TransmissionTimings> p_timings) { transmission_timings = p_timings; }
    Ref<TransmissionTimings> get_transmission_timings() const { return transmission_timings; }
    void set_msrp(float p_msrp) { msrp = p_msrp; }
    float get_msrp() const { return msrp; }
    void set_zero_to_sixty(float p_zero_to_sixty) { zero_to_sixty = p_zero_to_sixty; }
    float get_zero_to_sixty() const { return zero_to_sixty; }
    void set_top_speed(float p_top_speed) { top_speed = p_top_speed; }
    float get_top_speed() const { return top_speed; }
    void set_scene(Ref<PackedScene> p_scene) { scene = p_scene; }
    Ref<PackedScene> get_scene() const { return scene; }
    void set_image(Ref<Texture2D> p_image) { image = p_image; }
    Ref<Texture2D> get_image() const { return image; }
};

VARIANT_ENUM_CAST(TransmissionType);
VARIANT_ENUM_CAST(EngineType);

#endif // CAR_H
