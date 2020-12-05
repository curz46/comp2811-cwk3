## Setup instructions

This README contains instructions for UNIX, specifically ArchLinux. If you're using a different distribution you will need to find the equivalent packages.

```
pacman -Syyu qt5-base
# gst-plugins-* fixes 'No decoder installed for quicktime' error
pacman -Syyu gstreamer gst-libav gst-plugins-good gst-plugins-ugly
```

Now download the videos.zip file from https://leeds365-my.sharepoint.com/personal/scstke_leeds_ac_uk/_layouts/15/onedrive.aspx?id=%2Fpersonal%2Fscstke%5Fleeds%5Fac%5Fuk%2FDocuments%2Fcomp2811%5F2020%5Ffiles%2Fvideos%2Ezip&parent=%2Fpersonal%2Fscstke%5Fleeds%5Fac%5Fuk%2FDocuments%2Fcomp2811%5F2020%5Ffiles&originalPath=aHR0cHM6Ly9sZWVkczM2NS1teS5zaGFyZXBvaW50LmNvbS86dTovZy9wZXJzb25hbC9zY3N0a2VfbGVlZHNfYWNfdWsvRWNHbnRjTC1LM0pPaWFaRjRUX3VhQTRCSG42VVNicTJFNTVrRl9CVGZkcFBhZz9ydGltZT14djctUVF1WjJFZw and extract it into `videos` in the root of this project.

## Build & execute instructions

```
# Execute on initial build
mkdir build && cd build
qmake ..
# Execute each build
make -B
./tomeo
```
