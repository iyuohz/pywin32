// This file implements the IProvideExpressionContexts Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PythonCOM.h"
#include "PythonCOMServer.h"
#include "PyIProvideExpressionContexts.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIProvideExpressionContexts::PyIProvideExpressionContexts(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIProvideExpressionContexts::~PyIProvideExpressionContexts() {}

/* static */ IProvideExpressionContexts *PyIProvideExpressionContexts::GetI(PyObject *self)
{
    return (IProvideExpressionContexts *)PyIUnknown::GetI(self);
}

// @pymethod |PyIProvideExpressionContexts|EnumExpressionContexts|Description of EnumStackFrames.
PyObject *PyIProvideExpressionContexts::EnumExpressionContexts(PyObject *self, PyObject *args)
{
    IProvideExpressionContexts *pIRDAT = GetI(self);
    if (pIRDAT == NULL)
        return NULL;
    IEnumDebugExpressionContexts *ppedsf;
    if (!PyArg_ParseTuple(args, ":EnumExpressionContexts"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIRDAT->EnumExpressionContexts(&ppedsf);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    return PyCom_PyObjectFromIUnknown(ppedsf, IID_IEnumDebugExpressionContexts, FALSE);
}

// @object PyIProvideExpressionContexts|Description of the interface
static struct PyMethodDef PyIProvideExpressionContexts_methods[] = {
    {"EnumExpressionContexts", PyIProvideExpressionContexts::EnumExpressionContexts,
     1},  // @pymeth EnumExpressionContexts|Description of EnumExpressionContexts
    {NULL}};

PyComTypeObject PyIProvideExpressionContexts::type("PyIProvideExpressionContexts", &PyIUnknown::type,
                                                   sizeof(PyIProvideExpressionContexts),
                                                   PyIProvideExpressionContexts_methods,
                                                   GET_PYCOM_CTOR(PyIProvideExpressionContexts));
// ---------------------------------------------------
//
// Gateway Implementation

STDMETHODIMP PyGProvideExpressionContexts::EnumExpressionContexts(
    /* [out] */ IEnumDebugExpressionContexts __RPC_FAR *__RPC_FAR *ppedsf)
{
    PY_GATEWAY_METHOD;
    if (ppedsf == NULL)
        return E_POINTER;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("EnumExpressionContexts", &result);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject *obppedsf;
    if (!PyArg_Parse(result, "O", &obppedsf))
        return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obppedsf, IID_IEnumDebugExpressionContexts, (void **)ppedsf,
                                               TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    Py_DECREF(result);
    return hr;
}
