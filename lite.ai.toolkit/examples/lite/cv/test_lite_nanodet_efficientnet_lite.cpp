//
// Created by DefTruth on 2021/10/5.
//

#include "lite/lite.h"

static void test_default()
{
  std::string onnx_path = "../../../examples/hub/onnx/cv/nanodet-EfficientNet-Lite2_512.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_detection_1.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_nanodet_efficientnet_lite_1.jpg";

  // 1. Test Default Engine ONNXRuntime
  lite::cv::detection::NanoDetEfficientNetLite *nanodet =
      new lite::cv::detection::NanoDetEfficientNetLite(onnx_path); // default

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  nanodet->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "Default Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete nanodet;

}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string onnx_path = "../../../examples/hub/onnx/cv/nanodet-EfficientNet-Lite2_512.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_detection_2.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_nanodet_efficientnet_lite_2.jpg";

  // 2. Test Specific Engine ONNXRuntime
  lite::onnxruntime::cv::detection::NanoDetEfficientNetLite *nanodet =
      new lite::onnxruntime::cv::detection::NanoDetEfficientNetLite(onnx_path);

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  nanodet->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "ONNXRuntime Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete nanodet;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../../../examples/hub/mnn/cv/nanodet-EfficientNet-Lite2_512.mnn";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_detection_2.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_nanodet_efficientnet_lite_mnn_2.jpg";

  // 3. Test Specific Engine MNN
  lite::mnn::cv::detection::NanoDetEfficientNetLite *nanodet =
      new lite::mnn::cv::detection::NanoDetEfficientNetLite(mnn_path);

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  nanodet->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);
  cv::imwrite(save_img_path, img_bgr);

  std::cout << "MNN Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete nanodet;
#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
  std::string param_path = "../../../examples/hub/ncnn/cv/nanodet-EfficientNet-Lite2_512-opt.param";
  std::string bin_path = "../../../examples/hub/ncnn/cv/nanodet-EfficientNet-Lite2_512-opt.bin";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_detection_2.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_nanodet_efficientnet_lite_ncnn_2.jpg";

  // 4. Test Specific Engine NCNN
  lite::ncnn::cv::detection::NanoDetEfficientNetLite *nanodet =
      new lite::ncnn::cv::detection::NanoDetEfficientNetLite(
          param_path, bin_path,1, 512, 512);

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  nanodet->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);
  cv::imwrite(save_img_path, img_bgr);

  std::cout << "NCNN Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete nanodet;
#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
  std::string proto_path = "../../../examples/hub/tnn/cv/nanodet-EfficientNet-Lite2_512.opt.tnnproto";
  std::string model_path = "../../../examples/hub/tnn/cv/nanodet-EfficientNet-Lite2_512.opt.tnnmodel";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_detection_2.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_nanodet_efficientnet_lite_tnn_2.jpg";

  // 4. Test Specific Engine TNN
  lite::tnn::cv::detection::NanoDetEfficientNetLite *nanodet =
      new lite::tnn::cv::detection::NanoDetEfficientNetLite(proto_path, model_path);

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  nanodet->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);
  cv::imwrite(save_img_path, img_bgr);

  std::cout << "TNN Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete nanodet;
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
