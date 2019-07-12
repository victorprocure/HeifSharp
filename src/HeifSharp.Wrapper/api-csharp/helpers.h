#pragma once

#define DLL_EXPORTS
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#define CONCAT(a, b) a##b

using namespace HEIFPP;

#define CHECK_PTR_RETURN_VAL(objToCheck, retVal) \
    if (objToCheck == NULL)                      \
        return retVal;

#define CHECK_PTR_RETURN_NULL_PTR(objToCheck) CHECK_PTR_RETURN_VAL(objToCheck, nullptr)
#define CHECK_PTR_RETURN(objToCheck) CHECK_PTR_RETURN_VAL(objToCheck, )

#define IMPL_NATIVE_METHOD(application_identity, return_type, method_name) \
    DLL_API return_type application_identity##method_name

#define EVALUATE_NATIVE_METHOD(application_identity, return_type, method_name) \
    IMPL_NATIVE_METHOD(application_identity, return_type, method_name)

#define NATIVE_METHOD_ARG(returnType, methodName, ...)                                                  \
    EVALUATE_NATIVE_METHOD(CLASS_NAME, returnType, methodName)(CLASS_NAME * nativeObject, __VA_ARGS__); \
    EVALUATE_NATIVE_METHOD(CLASS_NAME, returnType, methodName)(CLASS_NAME * nativeObject, __VA_ARGS__)

#define NATIVE_METHOD(returnType, methodName)                                              \
    EVALUATE_NATIVE_METHOD(CLASS_NAME, returnType, methodName)(CLASS_NAME * nativeObject); \
    EVALUATE_NATIVE_METHOD(CLASS_NAME, returnType, methodName)(CLASS_NAME * nativeObject)

#define NATIVE_CONSTRUCTOR_NAMED_ARG(methodName, ...)                           \
    EVALUATE_NATIVE_METHOD(CLASS_NAME, CLASS_NAME##*, methodName)(__VA_ARGS__); \
    EVALUATE_NATIVE_METHOD(CLASS_NAME, CLASS_NAME##*, methodName)(__VA_ARGS__)

#define NATIVE_CONSTRUCTOR_ARG(...) NATIVE_CONSTRUCTOR_NAMED_ARG(Create, __VA_ARGS__)

#define NATIVE_CONSTRUCTOR                                       \
    EVALUATE_NATIVE_METHOD(CLASS_NAME, CLASS_NAME##*, Create)(); \
    EVALUATE_NATIVE_METHOD(CLASS_NAME, CLASS_NAME##*, Create)()