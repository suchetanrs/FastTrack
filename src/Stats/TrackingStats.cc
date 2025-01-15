#include "Stats/TrackingStats.h"
#include <sstream>  

using namespace std;

// std::vector<std::pair<long unsigned int, double>> TrackingStats::tracking_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::orbExtraction_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::stereoMatch_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::trackWithMotionModel_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::TWM_poseEstimation_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::TWM_poseOptimization_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::relocalization_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::trackLocalMap_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::updateLocalMap_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::updateLocalKF_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::updateLocalPoints_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::searchLocalPoints_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::SLP_frameMapPointsItr_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::SLP_localMapPointsItr_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::SLP_searchByProjection_time;
// std::vector<std::pair<long unsigned int, double>> TrackingStats::TLM_poseOptimization_time;
// std::vector<std::pair<long unsigned int, int>> TrackingStats::num_local_mappoints;
// double TrackingStats::orbExtraction_init_time = 0;
// double TrackingStats::stereoMatch_init_time = 0;
// double TrackingStats::searchLocalPoints_init_time = 0;
// double TrackingStats::poseEstimation_init_time = 0;
// int TrackingStats::num_frames_lost = 0;

void TrackingStats::saveStats(const string &file_path) {
#ifdef REGISTER_STATS
    string data_path = file_path + "/data/";
    cout << "Writing stats data into file: " << data_path << '\n';
    if (mkdir(data_path.c_str(), 0755) == -1) {
        std::cerr << "[TrackingStats:] Error creating directory: " << strerror(errno) << std::endl;
    }

    KernelController::saveKernelsStats(data_path);

    std::ofstream myfile;

    myfile.open(data_path + "/tracking_time.txt");
    for (const auto& p : tracking_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/orbExtraction_time.txt");
    for (const auto& p : orbExtraction_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/stereoMatch_time.txt");
    for (const auto& p : stereoMatch_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/trackWithMotionModel_time.txt");
    for (const auto& p : trackWithMotionModel_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/TWM_poseEstimation_time.txt");
    for (const auto& p : TWM_poseEstimation_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/TWM_poseOptimization_time.txt");
    for (const auto& p : TWM_poseOptimization_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/relocalization_time.txt");
    for (const auto& p : relocalization_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/trackLocalMap_time.txt");
    for (const auto& p : trackLocalMap_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/updateLocalMap_time.txt");
    for (const auto& p : updateLocalMap_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/updateLocalKF_time.txt");
    for (const auto& p : updateLocalKF_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/updateLocalPoints_time.txt");
    for (const auto& p : updateLocalPoints_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/searchLocalPoints_time.txt");
    for (const auto& p : searchLocalPoints_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/SLP_frameMapPointsItr_time.txt");
    for (const auto& p : SLP_frameMapPointsItr_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/SLP_localMapPointsItr_time.txt");
    for (const auto& p : SLP_localMapPointsItr_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/SLP_searchByProjection_time.txt");
    for (const auto& p : SLP_searchByProjection_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/TLM_poseOptimization_time.txt");
    for (const auto& p : TLM_poseOptimization_time) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/num_local_mappoints.txt");
    for (const auto& p : num_local_mappoints) {
        myfile << p.first << ": " << p.second << std::endl;
    }
    myfile.close();

    myfile.open(data_path + "/kernel_initialization_time.txt");
    myfile << "total_initialization_time: " << orbExtraction_init_time + stereoMatch_init_time + searchLocalPoints_init_time + poseEstimation_init_time << std::endl;
    myfile << "orbExtraction_initialization_time: " << orbExtraction_init_time << std::endl;
    myfile << "stereoMatch_initialization_time: " << stereoMatch_init_time << std::endl;
    myfile << "searchLocalPoints_initialization_time: " << searchLocalPoints_init_time << std::endl;
    myfile << "poseEstimation_initialization_time: " << poseEstimation_init_time << std::endl;
    myfile.close();

    myfile.open(data_path + "/num_frames_lost.txt");
    myfile << num_frames_lost << std::endl;
    myfile.close(); 
#endif
}