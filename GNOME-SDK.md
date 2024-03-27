
seems GNOME SDK already have libjxl 0.9

because it is not linked to our libjxl 0.10 version when we do ldd check

```shell
stripping: files/lib/libjxl_cms.so.0.10.2
stripping: files/lib/libjxl.so.0.10.2
stripping: files/lib/libjxl_threads.so.0.10.2
Committing stage build-libjxl to cache
========================================================================
Building module demo-jxl-app in /home/ttys3/repo/flatpak/flathub/.flatpak-builder/build/demo-jxl-app-4
========================================================================
Running: echo "hello world"
hello world
Running: make clean
rm -f jxl_info_dump
Running: make
gcc -Wall -Wextra main.c -o jxl_info_dump -ljxl
Running: ldd ./jxl_info_dump
	linux-vdso.so.1 (0x00007fffd70bd000)
	libjxl.so.0.9 => /usr/lib/x86_64-linux-gnu/libjxl.so.0.9 (0x00007f1109800000)
	libc.so.6 => /usr/lib/x86_64-linux-gnu/libc.so.6 (0x00007f1109613000)
	libjxl_cms.so.0.9 => /usr/lib/x86_64-linux-gnu/libjxl_cms.so.0.9 (0x00007f1109c7d000)
	libbrotlidec.so.1 => /usr/lib/x86_64-linux-gnu/libbrotlidec.so.1 (0x00007f1109c70000)
	libbrotlienc.so.1 => /usr/lib/x86_64-linux-gnu/libbrotlienc.so.1 (0x00007f1109bde000)
	libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f1109200000)
	libm.so.6 => /usr/lib/x86_64-linux-gnu/libm.so.6 (0x00007f110952a000)
	libgcc_s.so.1 => /usr/lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f1109bb7000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f1109c99000)
	liblcms2.so.2 => /usr/lib/x86_64-linux-gnu/liblcms2.so.2 (0x00007f1109b51000)
	libbrotlicommon.so.1 => /usr/lib/x86_64-linux-gnu/libbrotlicommon.so.1 (0x00007f1109b2e000)
Running: ./jxl_info_dump ./logo.jxl
Image dimensions: 1000 x 1000
Color space: 3
Bit depth: 8
Orientation: 1
Committing stage build-demo-jxl-app to cache

Cleaning up
...
Removing files/lib/libjxl_threads.so.0.10.2
Removing files/lib/libjxl_threads.so.0.10
Removing files/lib/libjxl_threads.so
Removing files/lib/libjxl_cms.so.0.10.2
Removing files/lib/libjxl_cms.so.0.10
Removing files/lib/libjxl_cms.so
Removing files/lib/libjxl.so.0.10.2
Removing files/lib/libjxl.so.0.10
Removing files/lib/libjxl.so
Removing files/lib/libhwy_test.so.1.1.0
Removing files/lib/libhwy_test.so.1
Removing files/lib/libhwy_test.so
Removing files/lib/libhwy.so.1.1.0
Removing files/lib/libhwy.so.1
Removing files/lib/libhwy.so
Removing files/lib/libavif.so.16.0.4
Removing files/lib/libavif.so.16
Removing files/lib/libavif.so

...
```
