#include "module_audio_wrapper.h"
#include "wave_wrapper.h"
#include "sound_wrapper.h"
#include "audiostream_wrapper.h"
#ifdef RAYLIB_MUSIC
#include "music_wrapper.h"
#endif
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/string.h"

//================================================================//
// module: audio
//================================================================//

//----------------------------------------------------------------//
/**	@ruby	InitAudioDevice
	@text	Initialize audio device and context
*/
static mrb_value
mrb_raylib_module_audio_init_audio_device(mrb_state* mrb, mrb_value self)
{
	InitAudioDevice();

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	CloseAudioDevice
	@text	Close the audio device and context (and music stream)
*/
static mrb_value
mrb_raylib_module_audio_close_audio_device(mrb_state* mrb, mrb_value self)
{
	CloseAudioDevice();

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	IsAudioDeviceReady
	@text	Check if audio device is ready

	@out	Boolean Audio device ready
*/
static mrb_value
mrb_raylib_module_audio_is_audio_device_ready(mrb_state* mrb, mrb_value self)
{
	return mrb_bool_value(IsAudioDeviceReady());
}

//----------------------------------------------------------------//
/**	@ruby	SetMasterVolume
	@text	Set master volume (listener)

	@in		Float volume
*/
static mrb_value
mrb_raylib_module_audio_set_master_volume(mrb_state* mrb, mrb_value self)
{
	mrb_float volume;

	mrb_get_args(mrb, "f", &volume);

	SetMasterVolume(volume);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	LoadWave
	@text	Load wave data from file into RAM

	@in		String file Path
	@out	Wave wave
*/
static mrb_value
mrb_raylib_module_audio_load_wave(mrb_state* mrb, mrb_value self)
{
	mrb_value fileName;

	mrb_get_args(mrb, "S", &fileName);

	Wave wave = LoadWave(RSTRING_PTR(fileName));

	return mrb_raylib_wave_direct(mrb, &wave);
}

//----------------------------------------------------------------//
/**	@ruby	LoadSound
	@text	Load sound to memory

	@in		String file Path
	@out	Sound sound
*/
static mrb_value
mrb_raylib_module_audio_load_sound(mrb_state* mrb, mrb_value self)
{
	mrb_value fileName;

	mrb_get_args(mrb, "S", &fileName);

	Sound sound = LoadSound(RSTRING_PTR(fileName));

	return mrb_raylib_sound_direct(mrb, &sound);
}

//----------------------------------------------------------------//
/**	@ruby	LoadSoundFromWave
	@text	Load sound to memory from wave data

	@in		Wave wave
	@out	Sound sound
*/
static mrb_value
mrb_raylib_module_audio_load_sound_from_wave(mrb_state* mrb, mrb_value self)
{
	mrb_value wave;

	mrb_get_args(mrb, "o", &wave);

	Sound sound = LoadSoundFromWave(*mrb_raylib_wave_get_ptr(mrb, wave));

	return mrb_raylib_sound_direct(mrb, &sound);
}

//----------------------------------------------------------------//
/**	@ruby	UnloadWave
	@text	Unload wave data

	@in		Wave wave
*/
static mrb_value
mrb_raylib_module_audio_unload_wave(mrb_state* mrb, mrb_value self)
{
	mrb_value wave;

	mrb_get_args(mrb, "o", &wave);

	UnloadWave(*mrb_raylib_wave_get_ptr(mrb, wave));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	UnloadSound
	@text	Unload sound

	@in		Sound sound
*/
static mrb_value
mrb_raylib_module_audio_unload_sound(mrb_state* mrb, mrb_value self)
{
	mrb_value sound;

	mrb_get_args(mrb, "o", &sound);

	UnloadSound(*mrb_raylib_sound_get_ptr(mrb, sound));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	PlaySound
	@text	Play a sound

	@in		Sound sound
*/
static mrb_value
mrb_raylib_module_audio_play_sound(mrb_state* mrb, mrb_value self)
{
	mrb_value sound;

	mrb_get_args(mrb, "o", &sound);

	PlaySound(*mrb_raylib_sound_get_ptr(mrb, sound));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	PauseSound
	@text	Pause a sound

	@in		Sound sound
*/
static mrb_value
mrb_raylib_module_audio_pause_sound(mrb_state* mrb, mrb_value self)
{
	mrb_value sound;

	mrb_get_args(mrb, "o", &sound);

	PauseSound(*mrb_raylib_sound_get_ptr(mrb, sound));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	ResumeSound
	@text	Resume a paused sound

	@in		Sound sound
*/
static mrb_value
mrb_raylib_module_audio_resume_sound(mrb_state* mrb, mrb_value self)
{
	mrb_value sound;

	mrb_get_args(mrb, "o", &sound);

	ResumeSound(*mrb_raylib_sound_get_ptr(mrb, sound));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	StopSound
	@text	Stop playing a sound

	@in		Sound sound
*/
static mrb_value
mrb_raylib_module_audio_stop_sound(mrb_state* mrb, mrb_value self)
{
	mrb_value sound;

	mrb_get_args(mrb, "o", &sound);

	StopSound(*mrb_raylib_sound_get_ptr(mrb, sound));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	IsSoundPlaying
	@text	Check if a sound is currently playing

	@in		Sound sound
	@out	Boolean is_sound_playing
*/
static mrb_value
mrb_raylib_module_audio_is_sound_playing(mrb_state* mrb, mrb_value self)
{
	mrb_value sound;

	mrb_get_args(mrb, "o", &sound);

	return mrb_bool_value(IsSoundPlaying(*mrb_raylib_sound_get_ptr(mrb, sound)));
}

//----------------------------------------------------------------//
/**	@ruby	SetSoundVolume
	@text	Check if a sound is currently playing

	@in		Sound sound
	@in		Float volume
*/
static mrb_value
mrb_raylib_module_audio_set_sound_volume(mrb_state* mrb, mrb_value self)
{
	mrb_value sound;
	mrb_float volume;

	mrb_get_args(mrb, "of", &sound, &volume);

	SetSoundVolume(*mrb_raylib_sound_get_ptr(mrb, sound), volume);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	SetSoundPitch
	@text	Set pitch for a sound (1.0 is base level)

	@in		Sound sound
	@in		Float pitch
*/
static mrb_value
mrb_raylib_module_audio_set_sound_pitch(mrb_state* mrb, mrb_value self)
{
	mrb_value sound;
	mrb_float pitch;

	mrb_get_args(mrb, "of", &sound, &pitch);

	SetSoundPitch(*mrb_raylib_sound_get_ptr(mrb, sound), pitch);

	return self;
}

#ifdef RAYLIB_MUSIC
//----------------------------------------------------------------//
/**	@ruby	LoadMusicStream
	@text	Load music stream from file

	@in		String fileName
	@out	Music music
*/
static mrb_value
mrb_raylib_module_audio_load_music_stream(mrb_state* mrb, mrb_value self)
{
	mrb_value fileName;

	mrb_get_args(mrb, "S", &fileName);

	Music music = LoadMusicStream(RSTRING_PTR(fileName));

	return mrb_raylib_music_direct(mrb, music);
}

//----------------------------------------------------------------//
/**	@ruby	UnloadMusicStream
	@text	Unload music stream

	@in		Music music
*/
static mrb_value
mrb_raylib_module_audio_unload_music_stream(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	UnloadMusicStream(mrb_raylib_music_get_ptr(mrb, music));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	PlayMusicStream
	@text	Start music playing

	@in		Music music
*/
static mrb_value
mrb_raylib_module_audio_play_music_stream(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	PlayMusicStream(mrb_raylib_music_get_ptr(mrb, music));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	UpdateMusicStream
	@text	Updates buffers for music streaming

	@in		Music music
*/
static mrb_value
mrb_raylib_module_audio_update_music_stream(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	UpdateMusicStream(mrb_raylib_music_get_ptr(mrb, music));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	StopMusicStream
	@text	Stop music playing

	@in		Music music
*/
static mrb_value
mrb_raylib_module_audio_stop_music_stream(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	StopMusicStream(mrb_raylib_music_get_ptr(mrb, music));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	PauseMusicStream
	@text	Pause music playing

	@in		Music music
*/
static mrb_value
mrb_raylib_module_audio_pause_music_stream(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	PauseMusicStream(mrb_raylib_music_get_ptr(mrb, music));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	ResumeMusicStream
	@text	Resume playing paused music

	@in		Music music
*/
static mrb_value
mrb_raylib_module_audio_resume_music_stream(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	ResumeMusicStream(mrb_raylib_music_get_ptr(mrb, music));

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	IsMusicPlaying
	@text	Check if music is playing

	@in		Music music
	@out	Boolean is_music_playing
*/
static mrb_value
mrb_raylib_module_audio_is_music_playing(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	return mrb_bool_value(IsMusicPlaying(mrb_raylib_music_get_ptr(mrb, music)));
}

//----------------------------------------------------------------//
/**	@ruby	SetSoundVolume
	@text	Set volume for music (1.0 is max level)

	@in		Music music
	@in		Float volume
*/
static mrb_value
mrb_raylib_module_audio_set_music_volume(mrb_state* mrb, mrb_value self)
{
	mrb_value music;
	mrb_float volume;

	mrb_get_args(mrb, "of", &music, &volume);

	SetMusicVolume(mrb_raylib_music_get_ptr(mrb, music), volume);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	SetMusicPitch
	@text	Set pitch for a music (1.0 is base level)

	@in		Music music
	@in		Float pitch
*/
static mrb_value
mrb_raylib_module_audio_set_music_pitch(mrb_state* mrb, mrb_value self)
{
	mrb_value music;
	mrb_float pitch;

	mrb_get_args(mrb, "of", &music, &pitch);

	SetMusicPitch(mrb_raylib_music_get_ptr(mrb, music), pitch);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	SetMusicLoopCount
	@text	Set music loop count (loop repeats)

	@in		Music music
	@in		Fixnum loop_count
*/
static mrb_value
mrb_raylib_module_audio_set_music_loop_count(mrb_state* mrb, mrb_value self)
{
	mrb_value music;
	mrb_int loop_count;

	mrb_get_args(mrb, "oi", &music, &loop_count);

	SetMusicLoopCount(mrb_raylib_music_get_ptr(mrb, music), loop_count);

	return self;
}

//----------------------------------------------------------------//
/**	@ruby	GetMusicTimeLength
	@text	Get music time length (in seconds)

	@in		Music music
	@out	Float music_time_length
*/
static mrb_value
mrb_raylib_module_audio_get_music_time_length(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	return mrb_float_value(mrb, GetMusicTimeLength(mrb_raylib_music_get_ptr(mrb, music)));
}

//----------------------------------------------------------------//
/**	@ruby	GetMusicTimePlayed
	@text	Get current music time played (in seconds)

	@in		Music music
	@out	Float music_time_played
*/
static mrb_value
mrb_raylib_module_audio_get_music_time_played(mrb_state* mrb, mrb_value self)
{
	mrb_value music;

	mrb_get_args(mrb, "o", &music);

	return mrb_float_value(mrb, GetMusicTimePlayed(mrb_raylib_music_get_ptr(mrb, music)));
}
#endif


void
mrb_raylib_module_audio_init(mrb_state* mrb, struct RClass* mod_RayLib)
{
	// Audio device management functions
	mrb_define_module_function(mrb, mod_RayLib, "init_audio_device", mrb_raylib_module_audio_init_audio_device, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "close_audio_device", mrb_raylib_module_audio_close_audio_device, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "is_audio_device_ready", mrb_raylib_module_audio_is_audio_device_ready, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, mod_RayLib, "set_master_volume", mrb_raylib_module_audio_set_master_volume, MRB_ARGS_REQ(1));

	// Wave/Sound loading/unloading functions
	mrb_define_module_function(mrb, mod_RayLib, "load_wave", mrb_raylib_module_audio_load_wave, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "load_sound", mrb_raylib_module_audio_load_sound, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "load_sound_from_wave", mrb_raylib_module_audio_load_sound_from_wave, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "unload_wave", mrb_raylib_module_audio_unload_wave, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "unload_sound", mrb_raylib_module_audio_unload_sound, MRB_ARGS_REQ(1));

	// Wave/Sound management functions
	mrb_define_module_function(mrb, mod_RayLib, "play_sound", mrb_raylib_module_audio_play_sound, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "pause_sound", mrb_raylib_module_audio_pause_sound, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "resume_sound", mrb_raylib_module_audio_resume_sound, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "stop_sound", mrb_raylib_module_audio_stop_sound, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_sound_playing", mrb_raylib_module_audio_is_sound_playing, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "set_sound_volume", mrb_raylib_module_audio_set_sound_volume, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "set_sound_pitch", mrb_raylib_module_audio_set_sound_pitch, MRB_ARGS_REQ(2));

#ifdef RAYLIB_MUSIC
	// Music management functions
	mrb_define_module_function(mrb, mod_RayLib, "load_music_stream", mrb_raylib_module_audio_load_music_stream, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "unload_music_stream", mrb_raylib_module_audio_unload_music_stream, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "play_music_stream", mrb_raylib_module_audio_play_music_stream, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "update_music_stream", mrb_raylib_module_audio_update_music_stream, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "stop_music_stream", mrb_raylib_module_audio_stop_music_stream, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "pause_music_stream", mrb_raylib_module_audio_pause_music_stream, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "resume_music_stream", mrb_raylib_module_audio_resume_music_stream, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "is_music_playing", mrb_raylib_module_audio_is_music_playing, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "set_music_volume", mrb_raylib_module_audio_set_music_volume, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "set_music_pitch", mrb_raylib_module_audio_set_music_pitch, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "set_music_loop_count", mrb_raylib_module_audio_set_music_loop_count, MRB_ARGS_REQ(2));
	mrb_define_module_function(mrb, mod_RayLib, "get_music_time_length", mrb_raylib_module_audio_get_music_time_length, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, mod_RayLib, "get_music_time_played", mrb_raylib_module_audio_get_music_time_played, MRB_ARGS_REQ(1));
#endif

	// TODO: AudioStream management functions

}

void
mrb_raylib_module_audio_final(mrb_state* mrb, struct RClass* mod_RayLib)
{

}
