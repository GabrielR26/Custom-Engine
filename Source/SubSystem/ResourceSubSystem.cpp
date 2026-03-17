
#include "ResourceSubSystem.h"

Font* ResourceSubSystem::LoadFont(const string& _filePath)
{
	filesystem::path _fullPath = FONT_FOLDER + _filePath;
	Font* _font = new Font();
	if (_font->openFromFile(_fullPath))
	{
		LOG(format("Successfully load font from file: {}", _filePath), "ResourceSubSystem", terminal_color::bright_magenta);
		listFont.push_back(_font);
		return _font;
	}
	else
	{
		LOG_WARNING(format("Failed to load font from file: {}", _filePath));
		return nullptr;
	}
}

void ResourceSubSystem::UnloadFont(const Font* _font)
{
	vector<Font*>::const_iterator _it = find(listFont.begin(), listFont.end(), _font);
	if (_it != listFont.end())
		listFont.erase(_it);
}

void ResourceSubSystem::UnloadAllFont()
{
	const size_t _listFontSize = listFont.size();
	for (size_t i = 0; i < _listFontSize; i++)
	{
		delete listFont[i];
		listFont[i] = nullptr;
	}
	listFont.clear();
}

Texture* ResourceSubSystem::LoadTexture(const string& _filePath)
{
	filesystem::path _fullPath = TEXTURE_FOLDER + _filePath;
	Texture* _texture = new Texture();
	if (_texture->loadFromFile(_fullPath))
	{
		LOG(format("Successfully load texture from file: {}", _filePath), "ResourceSubSystem", terminal_color::bright_magenta);
		listTexture.push_back(_texture);
		return _texture;
	}
	else
	{
		LOG_WARNING(format("Failed to load texture from file: {}", _filePath));
		return nullptr;
	}
}

void ResourceSubSystem::UnloadTexture(const Texture* _texture)
{
	vector<Texture*>::const_iterator _it = find(listTexture.begin(), listTexture.end(), _texture);
	if (_it != listTexture.end())
		listTexture.erase(_it);
}

void ResourceSubSystem::UnloadAllTexture()
{
	const size_t _listTextureSize = listTexture.size();
	for (size_t i = 0; i < _listTextureSize; i++)
	{
		delete listTexture[i];
		listTexture[i] = nullptr;
	}
	listTexture.clear();
}

SoundBuffer* ResourceSubSystem::LoadSound(const string& _filePath)
{
	filesystem::path _fullPath = SOUND_FOLDER + _filePath;
	SoundBuffer* _soundBuffer = new SoundBuffer();
	if (_soundBuffer->loadFromFile(_fullPath))
	{
		LOG(format("Successfully load sound from file: {}", _filePath), "ResourceSubSystem", terminal_color::bright_magenta);
		listSound.push_back(_soundBuffer);
		return _soundBuffer;
	}
	else
	{
		LOG_WARNING(format("Failed to load sound from file: {}", _filePath));
		return nullptr;
	}
}

void ResourceSubSystem::UnloadSound(const SoundBuffer* _soundBuffer)
{
	vector<SoundBuffer*>::const_iterator _it = find(listSound.begin(), listSound.end(), _soundBuffer);
	if (_it != listSound.end())
		listSound.erase(_it);
}

void ResourceSubSystem::UnloadAllSound()
{
	const size_t _listSoundSize = listSound.size();
	for (size_t i = 0; i < _listSoundSize; i++)
	{
		delete listSound[i];
		listSound[i] = nullptr;
	}
	listSound.clear();
}

Music* ResourceSubSystem::LoadMusic(const string& _filePath)
{
	filesystem::path _fullPath = MUSIC_FOLDER + _filePath;
	Music* _music = new Music();
	if (_music->openFromFile(_fullPath))
	{
		LOG(format("Successfully load music from file: {}", _filePath), "ResourceSubSystem", terminal_color::bright_magenta);
		listMusic.push_back(_music);
		return _music;
	}
	else
	{
		LOG_WARNING(format("Failed to load music from file: {}", _filePath));
		return nullptr;
	}
}

void ResourceSubSystem::UnloadMusic(const Music* _music)
{
	vector<Music*>::const_iterator _it = find(listMusic.begin(), listMusic.end(), _music);
	if (_it != listMusic.end())
		listMusic.erase(_it);
}

void ResourceSubSystem::UnloadAllMusic()
{
	const size_t _listMusicSize = listMusic.size();
	for (size_t i = 0; i < _listMusicSize; i++)
	{
		delete listMusic[i];
		listMusic[i] = nullptr;
	}
	listMusic.clear();
}

void ResourceSubSystem::Initialize()
{
	LOG("Initialization", "ResourceSubSystem", terminal_color::bright_cyan);
	basicFont = LoadFont("Roboto-Regular.ttf");
}

void ResourceSubSystem::Shutdown()
{
	UnloadAllFont();
	UnloadAllMusic();
	UnloadAllSound();
	UnloadAllTexture();

	LOG("Shutting down", "ResourceSubSystem", terminal_color::bright_cyan);
	DestroyInstance();
}
