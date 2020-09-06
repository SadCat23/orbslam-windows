#pragma once

#include "System.h"
#include "UE4Linker.h"

#include <Converter.h>

namespace ORB_SLAM2 {

	void UE4Linker::Init(char* inVocFile, char* inSettingsFile, ORB_SLAM2::eSensor sensorType)
	{
		SLAM = new ORB_SLAM2::System(std::string(inVocFile), std::string(inSettingsFile), System::eSensor(sensorType));
	}

	void UE4Linker::TrackMonocular(const cv::Mat& image, double timestamp)
	{
		SLAM->TrackMonocular(image, timestamp);
	}

	void UE4Linker::ShutdownSlam()
	{
		SLAM->Shutdown();
	}

	UE4Linker* CreateUE4Linker(char* inVocFile, char* inSettingsFile, ORB_SLAM2::eSensor sensorType)
	{
		UE4Linker* linker = new UE4Linker();
		//linker->Init(inVocFile, inSettingsFile, sensorType);
		return linker;
	}















}