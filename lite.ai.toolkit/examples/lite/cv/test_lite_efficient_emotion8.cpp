//
// Created by DefTruth on 2021/7/24.
//

#include "lite/lite.h"

static void test_default()
{
  std::string onnx_path = "../../../examples/hub/onnx/cv/face-emotion-recognition-enet_b0_8_best_afew.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_emotion.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_emotion8.jpg";

  lite::cv::face::attr::EfficientEmotion8 *efficient_emotion8 =
      new lite::cv::face::attr::EfficientEmotion8(onnx_path);

  lite::types::Emotions emotions;
  cv::Mat img_bgr = cv::imread(test_img_path);
  efficient_emotion8->detect(img_bgr, emotions);

  lite::utils::draw_emotion_inplace(img_bgr, emotions);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "Default Version Detected Emotion: " << emotions.text
            << ": " << emotions.score << std::endl;

  delete efficient_emotion8;

}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string onnx_path = "../../../examples/hub/onnx/cv/face-emotion-recognition-enet_b0_8_best_afew.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_emotion.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_emotion8.jpg";

  lite::onnxruntime::cv::face::attr::EfficientEmotion8 *efficient_emotion8 =
      new lite::onnxruntime::cv::face::attr::EfficientEmotion8(onnx_path);

  lite::types::Emotions emotions;
  cv::Mat img_bgr = cv::imread(test_img_path);
  efficient_emotion8->detect(img_bgr, emotions);

  lite::utils::draw_emotion_inplace(img_bgr, emotions);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "ONNXRuntime Version Detected Emotion: " << emotions.text
            << ": " << emotions.score << std::endl;

  delete efficient_emotion8;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../../../examples/hub/mnn/cv/face-emotion-recognition-enet_b0_8_best_afew.mnn";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_emotion.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_emotion8_mnn.jpg";

  lite::mnn::cv::face::attr::EfficientEmotion8 *efficient_emotion8 =
      new lite::mnn::cv::face::attr::EfficientEmotion8(mnn_path);

  lite::types::Emotions emotions;
  cv::Mat img_bgr = cv::imread(test_img_path);
  efficient_emotion8->detect(img_bgr, emotions);

  lite::utils::draw_emotion_inplace(img_bgr, emotions);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "MNN Version Detected Emotion: " << emotions.text
            << ": " << emotions.score << std::endl;

  delete efficient_emotion8;
#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
  std::string param_path = "../../../examples/hub/ncnn/cv/face-emotion-recognition-enet_b0_8_best_afew.opt.param";
  std::string bin_path = "../../../examples/hub/ncnn/cv/face-emotion-recognition-enet_b0_8_best_afew.opt.bin";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_emotion.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_emotion8_ncnn.jpg";

  lite::ncnn::cv::face::attr::EfficientEmotion8 *efficient_emotion8 =
      new lite::ncnn::cv::face::attr::EfficientEmotion8(param_path, bin_path);

  lite::types::Emotions emotions;
  cv::Mat img_bgr = cv::imread(test_img_path);
  efficient_emotion8->detect(img_bgr, emotions);

  lite::utils::draw_emotion_inplace(img_bgr, emotions);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "NCNN Version Detected Emotion: " << emotions.text
            << ": " << emotions.score << std::endl;

  delete efficient_emotion8;
#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
  std::string proto_path = "../../../examples/hub/tnn/cv/face-emotion-recognition-enet_b0_8_best_afew.opt.tnnproto";
  std::string model_path = "../../../examples/hub/tnn/cv/face-emotion-recognition-enet_b0_8_best_afew.opt.tnnmodel";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_emotion.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_emotion8_tnn.jpg";

  lite::tnn::cv::face::attr::EfficientEmotion8 *efficient_emotion8 =
      new lite::tnn::cv::face::attr::EfficientEmotion8(proto_path, model_path);

  lite::types::Emotions emotions;
  cv::Mat img_bgr = cv::imread(test_img_path);
  efficient_emotion8->detect(img_bgr, emotions);

  lite::utils::draw_emotion_inplace(img_bgr, emotions);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "TNN Version Detected Emotion: " << emotions.text
            << ": " << emotions.score << std::endl;

  delete efficient_emotion8;
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
