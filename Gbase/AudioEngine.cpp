#include "AudioEngine.h"
#include <Extension/SDL_mixer.h>
#include "GameBaseException.h"

AudioEngine::AudioEngine(int frequency, AudioEngine::Format format, int channels, int chunk_size)
{
	initialized = false;
	if( Mix_OpenAudio( frequency, static_cast<Uint16>(format), channels, chunk_size ) == -1 )
		throw GameBaseException();

	initialized = true;
}


AudioEngine::~AudioEngine(void)
{
	if (initialized)
	{
		for (auto i = Musics.begin(); i != Musics.end(); i++)
			Mix_FreeMusic(i->second);

		for (auto i = SFx.begin(); i != SFx.end(); i++)
			Mix_FreeChunk(i->second);

		Mix_CloseAudio();
	}
}

void AudioEngine::Load(std::string uid, char* path, AudioEngine::Type type)
{
	switch (type)
	{
	case AudioEngine::Type::MUSIC:
		Musics[uid] = Mix_LoadMUS(path);
		if(Musics[uid] == nullptr)
			throw GameBaseException(Mix_GetError());
		break;
	case AudioEngine::Type::SFX:
		SFx[uid] = Mix_LoadWAV(path);
		if(SFx[uid] == nullptr)
			throw GameBaseException(Mix_GetError());
		break;
	default:
		break;
	}
}

void AudioEngine::PlayMusic(std::string uid, int times)
{
	if(currentState != State::OFF)
		Mix_PlayMusic(Musics[uid], times);
}

void AudioEngine::PauseMusic()
{
	Mix_PauseMusic();
}

void AudioEngine::ResumeMusic()
{
	Mix_ResumeMusic();
}

void AudioEngine::StopMusic()
{
	Mix_HaltMusic();
}

void AudioEngine::PlaySFx(std::string uid, int channel, int times)
{
	if(currentState != State::OFF)
		Mix_PlayChannel(channel, SFx[uid], times);
}

void AudioEngine::SetState(AudioEngine::State state)
{
	currentState = state;
	switch (state)
	{
	case AudioEngine::State::OFF:
		PauseMusic();
		break;
	case AudioEngine::State::LOW:
		break;
	case AudioEngine::State::MEDIUM:
		break;
	case AudioEngine::State::HIGH:
		ResumeMusic();
		break;
	default:
		break;
	}
}

AudioEngine::State AudioEngine::GetState()
{
	return currentState;
}