## Setup instructions

This README contains instructions for UNIX, specifically ArchLinux. If you're using a different distribution you will need to find the equivalent packages.

```
pacman -Syyu qt5-base
# gst-plugins-* fixes 'No decoder installed for quicktime' error
pacman -Syyu gstreamer gst-libav gst-plugins-good gst-plugins-ugly
```

Now download the videos.zip file from https://leeds365-my.sharepoint.com/:u:/g/personal/scstke_leeds_ac_uk/EcGntcL-K3JOiaZF4T_uaA4BHn6USbq2E55kF_BTfdpPag?e=n1quN  and extract it into `videos` in the root of this project.

## Build & execute instructions

```
# Execute on initial build
mkdir build && cd build
qmake ..
# Execute each build
make -B
./tomeo
```
