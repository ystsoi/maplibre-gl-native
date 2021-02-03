#include "lat_lng_bounds.hpp"
#include "lat_lng_bounds_zoom.hpp"

namespace mbgl {
namespace android {

jni::Local<jni::Object<LatLngBoundsZoom>> LatLngBoundsZoom::New(jni::JNIEnv& env, mbgl::LatLngBoundsZoom boundsZoom) {
    static auto& javaClass = jni::Class<LatLngBoundsZoom>::Singleton(env);
    static auto constructor = javaClass.GetConstructor<jni::Object<LatLngBounds>, double>(env);

    auto bounds = LatLngBounds::New(env, boundsZoom.getBounds());
    auto zoom = boundsZoom.getZoom();

    return javaClass.New(env, constructor, bounds, zoom);
}

mbgl::LatLngBoundsZoom LatLngBoundsZoom::getLatLngBoundsZoom(jni::JNIEnv& env, const jni::Object<LatLngBoundsZoom>& boundsZoom) {
    static auto& javaClass = jni::Class<LatLngBoundsZoom>::Singleton(env);
    static auto zoomField = javaClass.GetField<jni::jdouble>(env, "zoom");
    static auto latLngBoundsField = javaClass.GetField<jni::Object<LatLngBounds>>(env, "bounds");

    auto bounds = LatLngBounds::getLatLngBounds(env, boundsZoom.Get(env, latLngBoundsField));
    auto zoom = boundsZoom.Get(env, zoomField);

    auto retVal = mbgl::LatLngBoundsZoom(bounds, zoom);
    return retVal;
}

void LatLngBoundsZoom::registerNative(jni::JNIEnv& env) {
    jni::Class<LatLngBoundsZoom>::Singleton(env);
}

} // namespace android
} // namespace mbgl