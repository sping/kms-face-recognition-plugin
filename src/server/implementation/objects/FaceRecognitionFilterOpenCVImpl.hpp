/* Autogenerated with kurento-module-creator */

#ifndef __FACE_RECOGNITION_FILTER_OPENCV_IMPL_HPP__
#define __FACE_RECOGNITION_FILTER_OPENCV_IMPL_HPP__

#include <OpenCVProcess.hpp>
#include "FaceRecognitionFilter.hpp"
#include <EventHandler.hpp>
#include "face_rec/face_training.h"
#include "FaceTrainingModelParam.hpp"

using namespace nl;
using namespace sping;
using namespace face_rec;

namespace kurento
{
namespace module
{
namespace facerecognitionfilter
{

class FaceRecognitionFilterOpenCVImpl : public virtual OpenCVProcess
{

public:
  FaceRecognitionFilterOpenCVImpl ();

  virtual ~FaceRecognitionFilterOpenCVImpl () {};

  virtual void process (cv::Mat &mat);

  void loadModel (std::shared_ptr<FaceTrainingModelParam> faceTrainingParam);
  void setConfidenceThresholds (const std::vector<std::shared_ptr<AlgorithmConfidencePair>> &confidenceThresholds);
  void start ();
  void stop ();
  sigc::signal<void, FaceDetected> signalFaceDetected;

private:

    unique_ptr<FaceTraining> p_face_training;
    int targetWidth;
    int targetHeight;
    int minimumWidthFace;
    int minimumHeightFace;
    volatile bool running;
    map<OpenCVFaceRecognizer, double> confidenceThresholdsMap;
    vector<shared_ptr<AlgorithmPredictionResult>> results;
    vector<OpenCVFaceRecognizer> activeAlgorithms;
    vector<int> labels;
    vector<double> confidences;

    void initializeLabelsAndConfidences(vector<int>& labels, vector<double> &confidences, size_t size);

};

} /* facerecognitionfilter */
} /* module */
} /* kurento */

#endif /*  __FACE_RECOGNITION_FILTER_OPENCV_IMPL_HPP__ */
