vcpkg_from_github(
        OUT_SOURCE_PATH SOURCE_PATH
        REPO parthux1/ntfy-lib
        REF d8ed551
        SHA512 82d284752bc07dcbd81181b7e8acffa34b86b687f5a8504602a72d93f26c2ec080b689854c665a0f5acc27b216988ad68122de36eb295d7f495d9ffc30a69ede
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