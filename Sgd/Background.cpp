#include "Background.h"


void Background::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::PipeRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

void Background::Update(SDL_Renderer* ren, int random)
{
	SDL_Rect tmp_dest = getDest();
	
	if (tmp_dest.x < -50) {
		setDest(1920, 540-random, tmp_dest.h, tmp_dest.w);
		printf("\n\nrandom val-> %d, y set to ->%d", random, getDest().y);
	}
	tmp_dest = getDest();
	setDest(tmp_dest.x - 2, tmp_dest.y, tmp_dest.h, tmp_dest.w);
	

	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}
