vcpkg_from_github(
        OUT_SOURCE_PATH SOURCE_PATH
        REPO parthux1/ntfy-lib
        REF v1.0.0
        SHA512 fc137699dddc3ecd29643ff1308ae2207c85e1ce5611951c68316a5489701d8b673f9835da495a0f4b85970f0740b28ee6e16155298ba3aeb957cd6a4d95f7b4
        HEAD_REF master
)

vcpkg_cmake_configure(SOURCE_PATH ${SOURCE_PATH})
vcpkg_cmake_install()
vcpkg_cmake_config_fixup(CONFIG_PATH lib/cmake/ntfy-lib)

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")

file(REMOVE_RECURSE
        "${CURRENT_PACKAGES_DIR}/debug/include"
        "${CURRENT_PACKAGES_DIR}/debug/share"
)