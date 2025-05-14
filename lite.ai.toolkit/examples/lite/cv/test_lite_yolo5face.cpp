//
// Created by DefTruth on 2022/1/16.
//

#include "lite/lite.h"

static void test_default()
{
  std::string onnx_path = "../../../examples/hub/onnx/cv/yolov5face-s-640x640.onnx"; // yolov5s-face
  std::string test_img_path = "../../../examples/lite/resources/test_lite_face_detector.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_yolov5face.jpg";

  lite::cv::face::detect::YOLO5Face *yolov5face = new lite::cv::face::detect::YOLO5Face(onnx_path);

  std::vector<lite::types::BoxfWithLandmarks> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolov5face->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_with_landmarks_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "Default Version Done! Detected Face Num: " << detected_boxes.size() << std::endl;

  delete yolov5face;
}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string onnx_path = "../../../examples/hub/onnx/cv/yolov5face-s-640x640.onnx"; // yolov5s-face
  std::string test_img_path = "../../../examples/lite/resources/test_lite_face_detector_2.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_yolov5face_onnx_2.jpg";

  lite::onnxruntime::cv::face::detect::YOLO5Face *yolov5face =
      new lite::onnxruntime::cv::face::detect::YOLO5Face(onnx_path);

  std::vector<lite::types::BoxfWithLandmarks> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolov5face->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_with_landmarks_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "ONNXRuntime Version Done! Detected Face Num: " << detected_boxes.size() << std::endl;

  delete yolov5face;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../../../examples/hub/mnn/cv/yolov5face-s-640x640.mnn"; // yolov5s-face
  std::string test_img_path = "../../../examples/lite/resources/test_lite_face_detector_2.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_yolov5face_mnn_2.jpg";

  lite::mnn::cv::face::detect::YOLO5Face *yolov5face =
      new lite::mnn::cv::face::detect::YOLO5Face(mnn_path);

  std::vector<lite::types::BoxfWithLandmarks> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolov5face->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_with_landmarks_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "MNN Version Done! Detected Face Num: " << detected_boxes.size() << std::endl;

  delete yolov5face;
#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
  std::string param_path = "../../../examples/hub/ncnn/cv/yolov5face-s-640x640.opt.param"; // yolov5s-face
  std::string bin_path = "../../../examples/hub/ncnn/cv/yolov5face-s-640x640.opt.bin";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_face_detector_2.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_yolov5face_ncnn_2.jpg";

  lite::ncnn::cv::face::detect::YOLO5Face *yolov5face =
      new lite::ncnn::cv::face::detect::YOLO5Face(param_path, bin_path, 1, 640, 640);

  std::vector<lite::types::BoxfWithLandmarks> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolov5face->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_with_landmarks_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "NCNN Version Done! Detected Face Num: " << detected_boxes.size() << std::endl;

  delete yolov5face;
#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
  std::string proto_path = "../../../examples/hub/tnn/cv/yolov5face-s-640x640.opt.tnnproto"; // yolov5s-face
  std::string model_path = "../../../examples/hub/tnn/cv/yolov5face-s-640x640.opt.tnnmodel";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_face_detector_2.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_yolov5face_tnn_2.jpg";

  lite::tnn::cv::face::detect::YOLO5Face *yolov5face =
      new lite::tnn::cv::face::detect::YOLO5Face(proto_path, model_path);

  std::vector<lite::types::BoxfWithLandmarks> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolov5face->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_with_landmarks_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "TNN Version Done! Detected Face Num: " << detected_boxes.size() << std::endl;

  delete yolov5face;
#endif
}

static void test_lite()
{
  test_default();
  test_onnxruntime();
  test_mnn();
  test_ncnn();
  test_tnn();
}

int main(__unused int argc, __unused char *argv[])
{
  test_lite();
  return 0;
}