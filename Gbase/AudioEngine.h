#pragma once

struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;

#include <map>
class AudioEngine
{
public:
	enum class Format
	{
		S16LSB = 0x8010,
		S16MSB = 0x9010,
		S8 =	 0x8008,
		U16LSB = 0x0010,
		U16MSB = 0x1010,
		U8 =	 0x0008,
		DEFAULT= S16LSB
	};
	enum class Type
	{
		MUSIC,
		SFX
	};
	enum class State
	{
		OFF,
		LOW,
		MEDIUM,
		HIGH
	};
private:
	bool initialized;
	std::map<std::string, Mix_Chunk*> SFx;
	std::map<std::string, Mix_Music*> Musics;
	State currentState;
public:

	AudioEngine(int frequency = 22050, AudioEngine::Format format = AudioEngine::Format::DEFAULT, int channels = 2, int sampling_size = 4096);
	void Load(std::string uid, char* path, AudioEngine::Type type = AudioEngine::Type::SFX);

	void PlayMusic(std::string uid, int times = -1);
	void PauseMusic();
	void ResumeMusic();
	void StopMusic();
	void PlaySFx(std::string uid, int channel = -1, int times = 0);

	~AudioEngine();

	void SetState(AudioEngine::State state);
	AudioEngine::State GetState();
};