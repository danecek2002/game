//
// Created by Arina on 05.05.2023.
//

#include "MapBuilder.h"


MapBuilder::MapBuilder(Map* map){
    m_map=map;
}


Map* MapBuilder::getMap(){
    return m_map;
}
