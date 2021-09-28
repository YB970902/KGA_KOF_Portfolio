#pragma once
#include "Config.h"
#include "Singleton.h"
#include <map>

class Image;
class ImageManager : public Singleton<ImageManager>
{
private:
	map<eImageTag, Image*> mimageList;

public:
	void init();

	Image* GetImage(eImageTag eimageTag);

};

