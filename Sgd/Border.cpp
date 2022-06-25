#include "Border.h"

void Border::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTexture(), NULL, &getDest());
}
