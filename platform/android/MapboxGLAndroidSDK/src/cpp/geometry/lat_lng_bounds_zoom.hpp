#pragma once

#include <mbgl/util/noncopyable.hpp>
#include <mbgl/util/geo.hpp>
#include <mbgl/util/geometry.hpp>

#include <jni/jni.hpp>

namespace mbgl {
    namespace android {

        class LatLngBoundsZoom : private mbgl::util::noncopyable {
        public:

            static constexpr auto Name() { return "com/mapbox/mapboxsdk/geometry/LatLngBoundsZoom"; };

            static jni::Local<jni::Object<LatLngBoundsZoom>> New(jni::JNIEnv&, mbgl::LatLngBoundsZoom);

            static mbgl::LatLngBoundsZoom getLatLngBoundsZoom(jni::JNIEnv&, const jni::Object<LatLngBoundsZoom>&);

            static void registerNative(jni::JNIEnv&);
        };


    } // namespace android
} // namespace mbgl