# Tomeo (`comp2811-cwk3`)

Tomeo is a video player prototype for sports enthuasiasts. This repository
hosts all four iterations for our `comp2811` group project (coursework 3). 

| Group | Members                                                         |
| ----- | --------------------------------------------------------------- |
| `18`  | `sc19ab`, `ed18a2n`, `sc19d2c`, `sc19tgc`, `sc19aa`, `sc18ys`   |

See the branches for each iteration (named `it-1`, `it-2`, etc.)

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

Note that there is also a `test.sh` script to make rapid testing more convenient. This will fully build the entire project & run it, giving the `videos` directory
in the root of this project as an argument.
