#pragma once
#include <opencv2\core.hpp>


namespace ORB_SLAM2
{
	extern "C"
	{
		enum eSensor {
			MONOCULAR = 0,
			STEREO = 1,
			RGBD = 2
		};
		class UE4Linker
		{


		public:
			ORB_SLAM2::System* SLAM;
			void Init(char* inVocFile, char* inSettingsFile, eSensor cameraType = MONOCULAR);
			void TrackMonocular(const cv::Mat& image, double timestamp);
			void ShutdownSlam();
			int GetNumPoints();
			void GetAllMapPoint(int& outCount, float* pointData, char* fileToWrite);

		};
		UE4Linker* CreateUE4Linker(char* inVocFile, char* inSettingsFile, eSensor cameraType = MONOCULAR);

	}
}