==========
obs-gphoto
==========

Allows connecting DSLR cameras with obs-studio through gPhoto on Linux. At now tested only Canon cameras.

------
v0.5.0
------

Forked from https://github.com/dunkelstern/obs-gphoto (ibjpeg-turbo instead of ImageMagick), includes fixes from https://github.com/Doeme/obs-gphoto (fix_too_eager_termination, fix_double_free_on_terminate).

MODULES
=======
gPhoto live preview capture
---------------------------
   Allows capture cameras preview like video.

Timelapse photo capture
-----------------------
   Allows capture photo with some intervals(if interval set to 0 work only manual capture) or manual with hotkey and camera capture button, to show work in progress on good picture quality, or to compile timelapse video in future.

REQUIREMENTS
============

* *obs-studio*
* *libgphoto >= 2.5.10*
* *libjpeg-turbo* (probably already installed on your distribution)
* *libudev(optional)*

INSTALLATION
============

For ArchLinux:
--------------

Use the included PKGBUILD


For installation from source:
=============================

Fedora: 
-------
Install requirements: :code:`dnf install libgphoto2-devel obs-studio-devel libjpeg-devel systemd-devel`

General:
--------
* :code:`git clone https://github.com/maaleske/obs-gphoto`
* :code:`cd obs-gphoto`
* :code:`cmake . -DSYSTEM_INSTALL=0` for local installation or :code:`cmake . -DSYSTEM_INSTALL=1` for system installation
* :code:`make`
* :code:`make install`
