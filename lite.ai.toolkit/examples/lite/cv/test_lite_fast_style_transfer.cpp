//
// Created by DefTruth on 2021/6/24.
//

#include "lite/lite.h"

static void test_default()
{
  std::string candy_onnx_path = "../../../examples/hub/onnx/cv/style-candy-8.onnx";
  std::string mosaic_onnx_path = "../../../examples/hub/onnx/cv/style-mosaic-8.onnx";
  std::string pointilism_onnx_path = "../../../examples/hub/onnx/cv/style-pointilism-8.onnx";
  std::string rain_princess_onnx_path = "../../../examples/hub/onnx/cv/style-rain-princess-8.onnx";
  std::string udnie_onnx_path = "../../../examples/hub/onnx/cv/style-udnie-8.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_fast_style_transfer.jpg";
  std::string save_candy_path = "../../../examples/logs/test_lite_fast_style_transfer_candy.jpg";
  std::string save_mosaic_path = "../../../examples/logs/test_lite_fast_style_transfer_mosaic.jpg";
  std::string save_pointilism_path = "../../../examples/logs/test_lite_fast_style_transfer_pointilism.jpg";
  std::string save_rain_princess_path = "../../../examples/logs/test_lite_fast_style_transfer_rain_princes.jpg";
  std::string save_udnie_path = "../../../examples/logs/test_lite_fast_style_transfer_udnie.jpg";

  lite::cv::style::FastStyleTransfer *candy_fast_style_transfer =
      new lite::cv::style::FastStyleTransfer(candy_onnx_path);
  lite::cv::style::FastStyleTransfer *mosaic_fast_style_transfer =
      new lite::cv::style::FastStyleTransfer(mosaic_onnx_path);
  lite::cv::style::FastStyleTransfer *pointilism_fast_style_transfer =
      new lite::cv::style::FastStyleTransfer(pointilism_onnx_path);
  lite::cv::style::FastStyleTransfer *rain_princess_fast_style_transfer =
      new lite::cv::style::FastStyleTransfer(rain_princess_onnx_path);
  lite::cv::style::FastStyleTransfer *udnie_fast_style_transfer =
      new lite::cv::style::FastStyleTransfer(udnie_onnx_path);

  lite::types::StyleContent candy_style_content;
  lite::types::StyleContent mosaic_style_content;
  lite::types::StyleContent pointilism_style_content;
  lite::types::StyleContent rain_princess_style_content;
  lite::types::StyleContent udnie_style_content;

  cv::Mat img_bgr = cv::imread(test_img_path);

  candy_fast_style_transfer->detect(img_bgr, candy_style_content);
  mosaic_fast_style_transfer->detect(img_bgr, mosaic_style_content);
  pointilism_fast_style_transfer->detect(img_bgr, pointilism_style_content);
  rain_princess_fast_style_transfer->detect(img_bgr, rain_princess_style_content);
  udnie_fast_style_transfer->detect(img_bgr, udnie_style_content);

  if (candy_style_content.flag) cv::imwrite(save_candy_path, candy_style_content.mat);
  if (mosaic_style_content.flag) cv::imwrite(save_mosaic_path, mosaic_style_content.mat);
  if (pointilism_style_content.flag) cv::imwrite(save_pointilism_path, pointilism_style_content.mat);
  if (rain_princess_style_content.flag) cv::imwrite(save_rain_princess_path, rain_princess_style_content.mat);
  if (udnie_style_content.flag) cv::imwrite(save_udnie_path, udnie_style_content.mat);

  std::cout << "Default Version Style Transfer Done." << std::endl;

  delete candy_fast_style_transfer;
  delete mosaic_fast_style_transfer;
  delete pointilism_fast_style_transfer;
  delete rain_princess_fast_style_transfer;
  delete udnie_fast_style_transfer;

}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string candy_onnx_path = "../../../examples/hub/onnx/cv/style-candy-8.onnx";
  std::string mosaic_onnx_path = "../../../examples/hub/onnx/cv/style-mosaic-8.onnx";
  std::string pointilism_onnx_path = "../../../examples/hub/onnx/cv/style-pointilism-8.onnx";
  std::string rain_princess_onnx_path = "../../../examples/hub/onnx/cv/style-rain-princess-8.onnx";
  std::string udnie_onnx_path = "../../../examples/hub/onnx/cv/style-udnie-8.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_fast_style_transfer.jpg";
  std::string save_candy_path = "../../../examples/logs/test_onnx_fast_style_transfer_candy.jpg";
  std::string save_mosaic_path = "../../../examples/logs/test_onnx_fast_style_transfer_mosaic.jpg";
  std::string save_pointilism_path = "../../../examples/logs/test_onnx_fast_style_transfer_pointilism.jpg";
  std::string save_rain_princess_path = "../../../examples/logs/test_onnx_fast_style_transfer_rain_princes.jpg";
  std::string save_udnie_path = "../../../examples/logs/test_onnx_fast_style_transfer_udnie.jpg";

  lite::onnxruntime::cv::style::FastStyleTransfer *candy_fast_style_transfer =
      new lite::onnxruntime::cv::style::FastStyleTransfer(candy_onnx_path);
  lite::onnxruntime::cv::style::FastStyleTransfer *mosaic_fast_style_transfer =
      new lite::onnxruntime::cv::style::FastStyleTransfer(mosaic_onnx_path);
  lite::onnxruntime::cv::style::FastStyleTransfer *pointilism_fast_style_transfer =
      new lite::onnxruntime::cv::style::FastStyleTransfer(pointilism_onnx_path);
  lite::onnxruntime::cv::style::FastStyleTransfer *rain_princess_fast_style_transfer =
      new lite::onnxruntime::cv::style::FastStyleTransfer(rain_princess_onnx_path);
  lite::onnxruntime::cv::style::FastStyleTransfer *udnie_fast_style_transfer =
      new lite::onnxruntime::cv::style::FastStyleTransfer(udnie_onnx_path);

  lite::types::StyleContent candy_style_content;
  lite::types::StyleContent mosaic_style_content;
  lite::types::StyleContent pointilism_style_content;
  lite::types::StyleContent rain_princess_style_content;
  lite::types::StyleContent udnie_style_content;

  cv::Mat img_bgr = cv::imread(test_img_path);

  candy_fast_style_transfer->detect(img_bgr, candy_style_content);
  mosaic_fast_style_transfer->detect(img_bgr, mosaic_style_content);
  pointilism_fast_style_transfer->detect(img_bgr, pointilism_style_content);
  rain_princess_fast_style_transfer->detect(img_bgr, rain_princess_style_content);
  udnie_fast_style_transfer->detect(img_bgr, udnie_style_content);

  if (candy_style_content.flag) cv::imwrite(save_candy_path, candy_style_content.mat);
  if (mosaic_style_content.flag) cv::imwrite(save_mosaic_path, mosaic_style_content.mat);
  if (pointilism_style_content.flag) cv::imwrite(save_pointilism_path, pointilism_style_content.mat);
  if (rain_princess_style_content.flag) cv::imwrite(save_rain_princess_path, rain_princess_style_content.mat);
  if (udnie_style_content.flag) cv::imwrite(save_udnie_path, udnie_style_content.mat);

  std::cout << "ONNXRuntime Version Style Transfer Done." << std::endl;

  delete candy_fast_style_transfer;
  delete mosaic_fast_style_transfer;
  delete pointilism_fast_style_transfer;
  delete rain_princess_fast_style_transfer;
  delete udnie_fast_style_transfer;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../../../examples/hub/mnn/cv/style-candy-8.mnn";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_fast_style_transfer.jpg";
  std::string save_path = "../../../examples/logs/test_fast_style_transfer_candy_mnn.jpg";

  lite::mnn::cv::style::FastStyleTransfer *candy_fast_style_transfer =
      new lite::mnn::cv::style::FastStyleTransfer(mnn_path);

  lite::types::StyleContent candy_style_content;

  cv::Mat img_bgr = cv::imread(test_img_path);

  candy_fast_style_transfer->detect(img_bgr, candy_style_content);

  if (candy_style_content.flag) cv::imwrite(save_path, candy_style_content.mat);

  std::cout << "MNN Version Style Transfer Done." << std::endl;

  delete candy_fast_style_transfer;

#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
  std::string param_path = "../../../examples/hub/ncnn/cv/style-candy-8.opt.param";
  std::string bin_path = "../../../examples/hub/ncnn/cv/style-candy-8.opt.bin";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_fast_style_transfer.jpg";
  std::string save_path = "../../../examples/logs/test_fast_style_transfer_candy_ncnn.jpg";

  lite::ncnn::cv::style::FastStyleTransfer *candy_fast_style_transfer =
      new lite::ncnn::cv::style::FastStyleTransfer(param_path, bin_path);

  lite::types::StyleContent candy_style_content;

  cv::Mat img_bgr = cv::imread(test_img_path);

  candy_fast_style_transfer->detect(img_bgr, candy_style_content);


  if (candy_style_content.flag) cv::imwrite(save_path, candy_style_content.mat);

  std::cout << "NCNN Version Style Transfer Done." << std::endl;

  delete candy_fast_style_transfer;

#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
  std::string proto_path = "../../../examples/hub/tnn/cv/style-candy-8.opt.tnnproto";
  std::string model_path = "../../../examples/hub/tnn/cv/style-candy-8.opt.tnnmodel";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_fast_style_transfer.jpg";
  std::string save_path = "../../../examples/logs/test_fast_style_transfer_candy_tnn.jpg";

  lite::tnn::cv::style::FastStyleTransfer *candy_fast_style_transfer =
      new lite::tnn::cv::style::FastStyleTransfer(proto_path, model_path);

  lite::types::StyleContent candy_style_content;

  cv::Mat img_bgr = cv::imread(test_img_path);

  candy_fast_style_transfer->detect(img_bgr, candy_style_content);


  if (candy_style_content.flag) cv::imwrite(save_path, candy_style_content.mat);

  std::cout << "TNN Version Style Transfer Done." << std::endl;

  delete candy_fast_style_transfer;
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
