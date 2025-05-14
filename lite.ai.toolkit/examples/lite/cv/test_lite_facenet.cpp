//
// Created by DefTruth on 2021/7/5.
//

#include "lite/lite.h"

static void test_default()
{
  std::string onnx_path = "../../../examples/hub/onnx/cv/facenet_casia-webface_resnet.onnx";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_facenet_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_facenet_1.png";

  lite::cv::faceid::FaceNet *facenet = new lite::cv::faceid::FaceNet(onnx_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  facenet->detect(img_bgr0, face_content0);
  facenet->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "Default Version Detected Sim: " << sim << std::endl;
  }

  delete facenet;
}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string onnx_path = "../../../examples/hub/onnx/cv/facenet_casia-webface_resnet.onnx";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_facenet_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_facenet_2.png";

  lite::onnxruntime::cv::faceid::FaceNet *facenet =
      new lite::onnxruntime::cv::faceid::FaceNet(onnx_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  facenet->detect(img_bgr0, face_content0);
  facenet->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "ONNXRuntime Version Detected Sim: " << sim << std::endl;
  }

  delete facenet;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../../../examples/hub/mnn/cv/facenet_casia-webface_resnet.mnn";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_facenet_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_facenet_2.png";

  lite::mnn::cv::faceid::FaceNet *facenet =
      new lite::mnn::cv::faceid::FaceNet(mnn_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  facenet->detect(img_bgr0, face_content0);
  facenet->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "MNN Version Detected Sim: " << sim << std::endl;
  }

  delete facenet;
#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
  std::string param_path = "../../../examples/hub/ncnn/cv/facenet_casia-webface_resnet.opt.param";
  std::string bin_path = "../../../examples/hub/ncnn/cv/facenet_casia-webface_resnet.opt.bin";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_facenet_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_facenet_2.png";

  lite::ncnn::cv::faceid::FaceNet *facenet =
      new lite::ncnn::cv::faceid::FaceNet(param_path, bin_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  facenet->detect(img_bgr0, face_content0);
  facenet->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "NCNN Version Detected Sim: " << sim << std::endl;
  }

  delete facenet;
#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
  std::string proto_path = "../../../examples/hub/tnn/cv/facenet_casia-webface_resnet.tnnproto";
  std::string model_path = "../../../examples/hub/tnn/cv/facenet_casia-webface_resnet.tnnmodel";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_facenet_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_facenet_2.png";

  lite::tnn::cv::faceid::FaceNet *facenet =
      new lite::tnn::cv::faceid::FaceNet(proto_path, model_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  facenet->detect(img_bgr0, face_content0);
  facenet->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "TNN Version Detected Sim: " << sim << std::endl;
  }

  delete facenet;
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
