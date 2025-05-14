//
// Created by DefTruth on 2021/6/26.
//

#include "lite/lite.h"

static void test_default()
{
  std::string eccv16_onnx_path = "../../../examples/hub/onnx/cv/eccv16-colorizer.onnx";
  std::string siggraph17_onnx_path = "../../../examples/hub/onnx/cv/siggraph17-colorizer.onnx";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_colorizer_1.jpg";
  std::string test_img_path2 = "../../../examples/lite/resources/test_lite_colorizer_2.jpg";
  std::string test_img_path3 = "../../../examples/lite/resources/test_lite_colorizer_3.jpg";
  std::string test_img_path4 = "../../../examples/lite/resources/test_lite_colorizer_one_piece_0.png";
  std::string save_eccv_img_path1 = "../../../examples/logs/test_lite_eccv16_colorizer_1.jpg";
  std::string save_eccv_img_path2 = "../../../examples/logs/test_lite_eccv16_colorizer_2.jpg";
  std::string save_eccv_img_path3 = "../../../examples/logs/test_lite_eccv16_colorizer_3.jpg";
  std::string save_eccv_img_path4 = "../../../examples/logs/test_lite_eccv16_colorizer_one_piece_0.jpg";
  std::string save_siggraph_img_path1 = "../../../examples/logs/test_lite_siggraph17_colorizer_1.jpg";
  std::string save_siggraph_img_path2 = "../../../examples/logs/test_lite_siggraph17_colorizer_2.jpg";
  std::string save_siggraph_img_path3 = "../../../examples/logs/test_lite_siggraph17_colorizer_3.jpg";
  std::string save_siggraph_img_path4 = "../../../examples/logs/test_lite_siggraph17_colorizer_one_piece_0.jpg";

  lite::cv::colorization::Colorizer *eccv16_colorizer =
      new lite::cv::colorization::Colorizer(eccv16_onnx_path);
  lite::cv::colorization::Colorizer *siggraph17_colorizer =
      new lite::cv::colorization::Colorizer(siggraph17_onnx_path);

  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  cv::Mat img_bgr2 = cv::imread(test_img_path2);
  cv::Mat img_bgr3 = cv::imread(test_img_path3);
  cv::Mat img_bgr4 = cv::imread(test_img_path4);

  lite::types::ColorizeContent eccv16_colorize_content1;
  lite::types::ColorizeContent eccv16_colorize_content2;
  lite::types::ColorizeContent eccv16_colorize_content3;
  lite::types::ColorizeContent eccv16_colorize_content4;

  lite::types::ColorizeContent siggraph17_colorize_content1;
  lite::types::ColorizeContent siggraph17_colorize_content2;
  lite::types::ColorizeContent siggraph17_colorize_content3;
  lite::types::ColorizeContent siggraph17_colorize_content4;

  eccv16_colorizer->detect(img_bgr1, eccv16_colorize_content1);
  eccv16_colorizer->detect(img_bgr2, eccv16_colorize_content2);
  eccv16_colorizer->detect(img_bgr3, eccv16_colorize_content3);
  eccv16_colorizer->detect(img_bgr4, eccv16_colorize_content4);

  siggraph17_colorizer->detect(img_bgr1, siggraph17_colorize_content1);
  siggraph17_colorizer->detect(img_bgr2, siggraph17_colorize_content2);
  siggraph17_colorizer->detect(img_bgr3, siggraph17_colorize_content3);
  siggraph17_colorizer->detect(img_bgr4, siggraph17_colorize_content4);

  if (eccv16_colorize_content1.flag) cv::imwrite(save_eccv_img_path1, eccv16_colorize_content1.mat);
  if (eccv16_colorize_content2.flag) cv::imwrite(save_eccv_img_path2, eccv16_colorize_content2.mat);
  if (eccv16_colorize_content3.flag) cv::imwrite(save_eccv_img_path3, eccv16_colorize_content3.mat);
  if (eccv16_colorize_content4.flag) cv::imwrite(save_eccv_img_path4, eccv16_colorize_content4.mat);

  if (siggraph17_colorize_content1.flag) cv::imwrite(save_siggraph_img_path1, siggraph17_colorize_content1.mat);
  if (siggraph17_colorize_content2.flag) cv::imwrite(save_siggraph_img_path2, siggraph17_colorize_content2.mat);
  if (siggraph17_colorize_content3.flag) cv::imwrite(save_siggraph_img_path3, siggraph17_colorize_content3.mat);
  if (siggraph17_colorize_content4.flag) cv::imwrite(save_siggraph_img_path4, siggraph17_colorize_content4.mat);

  std::cout << "Default Version Colorization Done." << std::endl;

  delete eccv16_colorizer;
  delete siggraph17_colorizer;
}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string eccv16_onnx_path = "../../../examples/hub/onnx/cv/eccv16-colorizer.onnx";
  std::string siggraph17_onnx_path = "../../../examples/hub/onnx/cv/siggraph17-colorizer.onnx";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_colorizer_1.jpg";
  std::string test_img_path2 = "../../../examples/lite/resources/test_lite_colorizer_2.jpg";
  std::string test_img_path3 = "../../../examples/lite/resources/test_lite_colorizer_3.jpg";
  std::string test_img_path4 = "../../../examples/lite/resources/test_lite_colorizer_one_piece_0.png";
  std::string save_eccv_img_path1 = "../../../examples/logs/test_onnx_eccv16_colorizer_1.jpg";
  std::string save_eccv_img_path2 = "../../../examples/logs/test_onnx_eccv16_colorizer_2.jpg";
  std::string save_eccv_img_path3 = "../../../examples/logs/test_onnx_eccv16_colorizer_3.jpg";
  std::string save_eccv_img_path4 = "../../../examples/logs/test_onnx_eccv16_colorizer_one_piece_0.jpg";
  std::string save_siggraph_img_path1 = "../../../examples/logs/test_onnx_siggraph17_colorizer_1.jpg";
  std::string save_siggraph_img_path2 = "../../../examples/logs/test_onnx_siggraph17_colorizer_2.jpg";
  std::string save_siggraph_img_path3 = "../../../examples/logs/test_onnx_siggraph17_colorizer_3.jpg";
  std::string save_siggraph_img_path4 = "../../../examples/logs/test_onnx_siggraph17_colorizer_one_piece_0.jpg";

  lite::onnxruntime::cv::colorization::Colorizer *eccv16_colorizer =
      new lite::onnxruntime::cv::colorization::Colorizer(eccv16_onnx_path);
  lite::onnxruntime::cv::colorization::Colorizer *siggraph17_colorizer =
      new lite::onnxruntime::cv::colorization::Colorizer(siggraph17_onnx_path);

  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  cv::Mat img_bgr2 = cv::imread(test_img_path2);
  cv::Mat img_bgr3 = cv::imread(test_img_path3);
  cv::Mat img_bgr4 = cv::imread(test_img_path4);

  lite::types::ColorizeContent eccv16_colorize_content1;
  lite::types::ColorizeContent eccv16_colorize_content2;
  lite::types::ColorizeContent eccv16_colorize_content3;
  lite::types::ColorizeContent eccv16_colorize_content4;

  lite::types::ColorizeContent siggraph17_colorize_content1;
  lite::types::ColorizeContent siggraph17_colorize_content2;
  lite::types::ColorizeContent siggraph17_colorize_content3;
  lite::types::ColorizeContent siggraph17_colorize_content4;

  eccv16_colorizer->detect(img_bgr1, eccv16_colorize_content1);
  eccv16_colorizer->detect(img_bgr2, eccv16_colorize_content2);
  eccv16_colorizer->detect(img_bgr3, eccv16_colorize_content3);
  eccv16_colorizer->detect(img_bgr4, eccv16_colorize_content4);

  siggraph17_colorizer->detect(img_bgr1, siggraph17_colorize_content1);
  siggraph17_colorizer->detect(img_bgr2, siggraph17_colorize_content2);
  siggraph17_colorizer->detect(img_bgr3, siggraph17_colorize_content3);
  siggraph17_colorizer->detect(img_bgr4, siggraph17_colorize_content4);

  if (eccv16_colorize_content1.flag) cv::imwrite(save_eccv_img_path1, eccv16_colorize_content1.mat);
  if (eccv16_colorize_content2.flag) cv::imwrite(save_eccv_img_path2, eccv16_colorize_content2.mat);
  if (eccv16_colorize_content3.flag) cv::imwrite(save_eccv_img_path3, eccv16_colorize_content3.mat);
  if (eccv16_colorize_content4.flag) cv::imwrite(save_eccv_img_path4, eccv16_colorize_content4.mat);

  if (siggraph17_colorize_content1.flag) cv::imwrite(save_siggraph_img_path1, siggraph17_colorize_content1.mat);
  if (siggraph17_colorize_content2.flag) cv::imwrite(save_siggraph_img_path2, siggraph17_colorize_content2.mat);
  if (siggraph17_colorize_content3.flag) cv::imwrite(save_siggraph_img_path3, siggraph17_colorize_content3.mat);
  if (siggraph17_colorize_content4.flag) cv::imwrite(save_siggraph_img_path4, siggraph17_colorize_content4.mat);

  std::cout << "ONNXRuntime Version Colorization Done." << std::endl;

  delete eccv16_colorizer;
  delete siggraph17_colorizer;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../../../examples/hub/mnn/cv/eccv16-colorizer.mnn";
  // std::string mnn_path = "../../../examples/hub/mnn/cv/eccv16-colorizer.opt.mnn";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_colorizer_1.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_colorizer_1_mnn.jpg";

  lite::mnn::cv::colorization::Colorizer *eccv16_colorizer =
      new lite::mnn::cv::colorization::Colorizer(mnn_path, 8);

  cv::Mat img_bgr = cv::imread(test_img_path);

  lite::types::ColorizeContent eccv16_colorize_content;

  eccv16_colorizer->detect(img_bgr, eccv16_colorize_content);

  if (eccv16_colorize_content.flag) cv::imwrite(save_img_path, eccv16_colorize_content.mat);

  std::cout << "MNN Version Colorization Done." << std::endl;

  delete eccv16_colorizer;
#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
  std::string param_path = "../../../examples/hub/ncnn/cv/eccv16-colorizer.opt.param";
  std::string bin_path = "../../../examples/hub/ncnn/cv/eccv16-colorizer.opt.bin";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_colorizer_1.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_colorizer_1_ncnn.jpg";

  lite::ncnn::cv::colorization::Colorizer *eccv16_colorizer =
      new lite::ncnn::cv::colorization::Colorizer(param_path, bin_path, 1);

  cv::Mat img_bgr = cv::imread(test_img_path);

  lite::types::ColorizeContent eccv16_colorize_content;

  eccv16_colorizer->detect(img_bgr, eccv16_colorize_content);

  if (eccv16_colorize_content.flag) cv::imwrite(save_img_path, eccv16_colorize_content.mat);

  std::cout << "NCNN Version Colorization Done." << std::endl;

  delete eccv16_colorizer;
#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
  std::string proto_path = "../../../examples/hub/tnn/cv/eccv16-colorizer.opt.tnnproto";
  std::string model_path = "../../../examples/hub/tnn/cv/eccv16-colorizer.opt.tnnmodel";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_colorizer_1.jpg";
  std::string save_img_path = "../../../examples/logs/test_lite_colorizer_1_tnn.jpg";

  lite::tnn::cv::colorization::Colorizer *eccv16_colorizer =
      new lite::tnn::cv::colorization::Colorizer(proto_path, model_path, 1);

  cv::Mat img_bgr = cv::imread(test_img_path);

  lite::types::ColorizeContent eccv16_colorize_content;

  eccv16_colorizer->detect(img_bgr, eccv16_colorize_content);

  if (eccv16_colorize_content.flag) cv::imwrite(save_img_path, eccv16_colorize_content.mat);

  std::cout << "TNN Version Colorization Done." << std::endl;

  delete eccv16_colorizer;
#endif
}

static void test_lite()
{
  test_default();
  test_onnxruntime();
  test_mnn();
  // test_ncnn();
  test_tnn();
}

int main(__unused int argc, __unused char *argv[])
{
  test_lite();
  return 0;
}
