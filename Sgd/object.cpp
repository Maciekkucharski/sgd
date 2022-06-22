#include"object.h"

Object::Object() {
	Tex = NULL;
}

void Object::CreateTexture(const char* address, SDL_Renderer* ren, SDL_Texture* Tex) {
	Tex = TextureMenager::Texture(address, ren);
}

SDL_Texture* Object::getTexture() {
	return Tex;
}