//
// Created by twak on 11/11/2019.
//

#include "thumbnail.h"

void Thumbnail::init(VideoInfo* i) {
    setIcon( *(i->icon) );
    info =  i;
}

void Thumbnail::clicked() {
    emit jumpTo(info);
}
