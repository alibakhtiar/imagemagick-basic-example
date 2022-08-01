## ImageMagick Example



## نصب ImageMagick در لینوکس

تنظیمات configure براساس نیاز فعلی من تنظیم شده، ممکن است شما بخواهید آنها را تغییر دهید. درنهایت بعد از اجرای دستور configure بررسی کنید که تنظیمات درست باشد.

```
wget --no-check-certificate https://github.com/ImageMagick/ImageMagick/archive/refs/tags/7.1.0-44.zip
unzip 7.1.0-44.zip
cd ImageMagick-7.1.0-44
./configure --with-modules --enable-hdri=no --with-jemalloc=yes --with-tiff=no --with-jpeg=yes --with-openexr=no --with-png=yes --with-webp=yes --with-djvu=no --with-jbig=no --with-wmf=no
make -j4
make check -j4
sudo make install
sudo ldconfig /usr/local/lib
```

```
gcc example.c -lm `pkg-config --cflags --libs MagickWand`
```

```
-I/usr/local/include/ImageMagick-7
```

