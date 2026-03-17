#pragma once

#include "SubSystem.h"

#define FONT_FOLDER "Resources/Font/"
#define TEXTURE_FOLDER "Resources/Texture/"
#define SOUND_FOLDER "Resources/Sound/"
#define MUSIC_FOLDER "Resources/Music/"

/// <summary>
/// SubSystem to manage resources
/// </summary>
class ResourceSubSystem final : public SubSystem, public Singleton<ResourceSubSystem>
{
	vector<Font*> listFont = vector<Font*>();
	vector<Texture*> listTexture = vector<Texture*>();
	vector<SoundBuffer*> listSound = vector<SoundBuffer*>();
	vector<Music*> listMusic = vector<Music*>();
	Font* basicFont = nullptr;

public:
	Font* GetBasicFont() { return basicFont; }

public:
	ResourceSubSystem() = default;
	~ResourceSubSystem() = default;

	/// <summary>
	/// Load a font stored in "Font" folder
	/// </summary>
	/// <param name="_filePath"> The path of font file </param>
	/// <returns> The loaded font </returns>
	Font* LoadFont(const string& _filePath);
	/// <summary>
	/// Unload a listed font (Warning : nullify all references)
	/// </summary>
	/// <param name="_font"> Font to unload </param>
	void UnloadFont(const Font* _font);
	/// <summary>
	/// Unload all listed fonts
	/// </summary>
	void UnloadAllFont();

	/// <summary>
	/// Load a texture stored in "Texture" folder
	/// </summary>
	/// <param name="_filePath"> The path of texture file </param>
	/// <returns> The loaded texture </returns>
	Texture* LoadTexture(const string& _filePath);
	/// <summary>
	/// Unload a listed texture (Warning : nullify all references)
	/// </summary>
	/// <param name="_texture"> Texture to unload </param>
	void UnloadTexture(const Texture* _texture);
	/// <summary>
	/// Unload all listed textures
	/// </summary>
	void UnloadAllTexture();

	/// <summary>
	/// Load a SoundBuffer stored in "Sound" folder
	/// </summary>
	/// <param name="_filePath"> The path of sound file </param>
	/// <returns> The loaded soundBuffer </returns>
	SoundBuffer* LoadSound(const string& _filePath);
	/// <summary>
	/// Unload a listed SoundBuffer (Warning : nullify all references)
	/// </summary>
	/// <param name="_sound"> SoundBuffer to unload </param>
	void UnloadSound(const SoundBuffer* _soundBuffer);
	/// <summary>
	/// Unload all listed SoundBuffers
	/// </summary>
	void UnloadAllSound();

	/// <summary>
	/// Load a music stored in "Music" folder
	/// </summary>
	/// <param name="_filePath"> The path of music file </param>
	/// <returns> The loaded music </returns>
	Music* LoadMusic(const string& _filePath);
	/// <summary>
	/// Unload a listed music (Warning : nullify all references)
	/// </summary>
	/// <param name="_music"> Music to unload </param>
	void UnloadMusic(const Music* _music);
	/// <summary>
	/// Unload all listed Musics
	/// </summary>
	void UnloadAllMusic();

	// Inherited via SubSystem
	/// <summary>
	/// Initialize ResourceSubSystem
	/// </summary>
	void Initialize() override;
	/// <summary>
	/// Shutdown ResourceSubSystem
	/// </summary>
	void Shutdown() override;
};

