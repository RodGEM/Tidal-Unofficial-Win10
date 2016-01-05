#pragma once
#include <memory>
#include <vector>
#include <Api/TrackInfo.h>
#include "Mediators.h"
class AudioService {
	class BackgroundAudioConnection;
private:
	AudioService();
	std::shared_ptr<BackgroundAudioConnection> _connection;
public:
	~AudioService();

	friend AudioService& getAudioService();
	concurrency::task<void> resetPlaylistAndPlay(const std::vector<api::TrackInfo>& tracks, int startIndex, concurrency::cancellation_token cancelToken);
	std::int64_t getCurrentPlaybackTrackId() const;
	void onSuspending();
	void onResuming();
	void onBackgroundAudioFailureDetected();
	concurrency::task<void> wakeupDownloaderAsync(concurrency::cancellation_token cancelToken);
	concurrency::task<void> playAllLocalMusicAsync();
};