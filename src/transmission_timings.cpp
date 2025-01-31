#include "transmission_timings.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

TransmissionTimings::TransmissionTimings() {
}

TransmissionTimings::~TransmissionTimings() {
}

void TransmissionTimings::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add_point", "point"), &TransmissionTimings::add_point);
    ClassDB::bind_method(D_METHOD("remove_point", "index"), &TransmissionTimings::remove_point);
    ClassDB::bind_method(D_METHOD("clear_points"), &TransmissionTimings::clear_points);
    ClassDB::bind_method(D_METHOD("get_points"), &TransmissionTimings::get_points);
    ClassDB::bind_method(D_METHOD("set_points", "points"), &TransmissionTimings::set_points);

    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
}

void TransmissionTimings::add_point(const Vector2 &point) {
    points.push_back(point);
}

void TransmissionTimings::remove_point(int index) {
    if (index >= 0 && index < points.size()) {
        points.remove_at(index);
    }
}

void TransmissionTimings::clear_points() {
    points.clear();
}

Array TransmissionTimings::get_points() const {
    return points;
}

void TransmissionTimings::set_points(const Array &p_points) {
    points = p_points;
}
