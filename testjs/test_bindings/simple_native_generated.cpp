#include "simple_native_generated.hpp"

JSClass* S_AnotherClass::jsClass = NULL;
JSObject* S_AnotherClass::jsObject = NULL;

JSBool S_AnotherClass::jsConstructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_NewObject(cx, S_AnotherClass::jsClass, S_AnotherClass::jsObject, NULL);
	S_AnotherClass *cobj = new S_AnotherClass(obj);
	pointerShell_t *pt = (pointerShell_t *)JS_malloc(cx, sizeof(pointerShell_t));
	pt->flags = 0; pt->data = cobj;
	JS_SetPrivate(obj, pt);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
	return JS_TRUE;
}

void S_AnotherClass::jsFinalize(JSContext *cx, JSObject *obj)
{
	pointerShell_t *pt = (pointerShell_t *)JS_GetPrivate(obj);
	if (pt) {
		if (!(pt->flags & kPointerTemporary) && pt->data) delete (S_AnotherClass *)pt->data;
		JS_free(cx, pt);
	}
}

JSBool S_AnotherClass::jsPropertyGet(JSContext *cx, JSObject *obj, jsid _id, jsval *val)
{
	int32_t propId = JSID_TO_INT(_id);
	S_AnotherClass *cobj; JSGET_PTRSHELL(S_AnotherClass, cobj, obj);
	if (!cobj) return JS_FALSE;
	switch(propId) {
	case kAPublicField:
		do { jsval tmp; JS_NewNumberValue(cx, cobj->aPublicField, &tmp); JS_SET_RVAL(cx, val, tmp); } while (0);
		break;
	case kJustOneField:
		do { jsval tmp; JS_NewNumberValue(cx, cobj->getJustOneField(), &tmp); JS_SET_RVAL(cx, val, tmp); } while (0);
		break;
	default:
		break;
	}
	return JS_TRUE;
}

JSBool S_AnotherClass::jsPropertySet(JSContext *cx, JSObject *obj, jsid _id, JSBool strict, jsval *val)
{
	int32_t propId = JSID_TO_INT(_id);
	S_AnotherClass *cobj; JSGET_PTRSHELL(S_AnotherClass, cobj, obj);
	if (!cobj) return JS_FALSE;
	switch(propId) {
	case kAPublicField:
		do { uint32_t tmp; JS_ValueToECMAUint32(cx, *val, &tmp); cobj->aPublicField = tmp; } while (0);
		break;
	default:
		break;
	}
	return JS_TRUE;
}

void S_AnotherClass::jsCreateClass(JSContext *cx, JSObject *globalObj, const char *name)
{
	jsClass = (JSClass *)calloc(1, sizeof(JSClass));
	jsClass->name = name;
	jsClass->addProperty = JS_PropertyStub;
	jsClass->delProperty = JS_PropertyStub;
	jsClass->getProperty = JS_PropertyStub;
	jsClass->setProperty = JS_StrictPropertyStub;
	jsClass->enumerate = JS_EnumerateStub;
	jsClass->resolve = JS_ResolveStub;
	jsClass->convert = JS_ConvertStub;
	jsClass->finalize = jsFinalize;
	jsClass->flags = JSCLASS_HAS_PRIVATE;
		static JSPropertySpec properties[] = {
			{"aPublicField", kAPublicField, JSPROP_PERMANENT | JSPROP_SHARED, S_AnotherClass::jsPropertyGet, S_AnotherClass::jsPropertySet},
			{"justOneField", kJustOneField, JSPROP_PERMANENT | JSPROP_SHARED, S_AnotherClass::jsPropertyGet, S_AnotherClass::jsPropertySet},
			{0, 0, 0, 0, 0}
		};

		static JSFunctionSpec funcs[] = {
			JS_FN("doSomethingSimple", S_AnotherClass::jsdoSomethingSimple, 0, JSPROP_PERMANENT | JSPROP_SHARED),
			JS_FS_END
		};

		static JSFunctionSpec st_funcs[] = {
			JS_FS_END
		};

	jsObject = JS_InitClass(cx,globalObj,NULL,jsClass,S_AnotherClass::jsConstructor,0,properties,funcs,NULL,st_funcs);
}

JSBool S_AnotherClass::jsdoSomethingSimple(JSContext *cx, uint32_t argc, jsval *vp) {
	JSObject* obj = (JSObject *)JS_THIS_OBJECT(cx, vp);
	S_AnotherClass* self = NULL; JSGET_PTRSHELL(S_AnotherClass, self, obj);
	if (self == NULL) return JS_FALSE;
	if (argc == 0) {
		jsval *argv = JS_ARGV(cx, vp);
		self->doSomethingSimple();
		
		JS_SET_RVAL(cx, vp, JSVAL_TRUE);
		return JS_TRUE;
	}
	JS_SET_RVAL(cx, vp, JSVAL_TRUE);
	return JS_TRUE;
}

JSClass* S_SimpleNativeClass::jsClass = NULL;
JSObject* S_SimpleNativeClass::jsObject = NULL;

JSBool S_SimpleNativeClass::jsConstructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_NewObject(cx, S_SimpleNativeClass::jsClass, S_SimpleNativeClass::jsObject, NULL);
	S_SimpleNativeClass *cobj = new S_SimpleNativeClass(obj);
	pointerShell_t *pt = (pointerShell_t *)JS_malloc(cx, sizeof(pointerShell_t));
	pt->flags = 0; pt->data = cobj;
	JS_SetPrivate(obj, pt);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
	return JS_TRUE;
}

void S_SimpleNativeClass::jsFinalize(JSContext *cx, JSObject *obj)
{
	pointerShell_t *pt = (pointerShell_t *)JS_GetPrivate(obj);
	if (pt) {
		if (!(pt->flags & kPointerTemporary) && pt->data) delete (S_SimpleNativeClass *)pt->data;
		JS_free(cx, pt);
	}
}

JSBool S_SimpleNativeClass::jsPropertyGet(JSContext *cx, JSObject *obj, jsid _id, jsval *val)
{
	int32_t propId = JSID_TO_INT(_id);
	S_SimpleNativeClass *cobj; JSGET_PTRSHELL(S_SimpleNativeClass, cobj, obj);
	if (!cobj) return JS_FALSE;
	switch(propId) {
	case kSomeField:
		do { jsval tmp; JS_NewNumberValue(cx, cobj->getSomeField(), &tmp); JS_SET_RVAL(cx, val, tmp); } while (0);
		break;
	case kSomeOtherField:
		do { jsval tmp; JS_NewNumberValue(cx, cobj->getSomeOtherField(), &tmp); JS_SET_RVAL(cx, val, tmp); } while (0);
		break;
	case kAnotherMoreComplexField:
		do { JSString *tmp = JS_NewStringCopyZ(cx, cobj->getAnotherMoreComplexField()); JS_SET_RVAL(cx, val, STRING_TO_JSVAL(tmp)); } while (0);
		break;
	default:
		break;
	}
	return JS_TRUE;
}

JSBool S_SimpleNativeClass::jsPropertySet(JSContext *cx, JSObject *obj, jsid _id, JSBool strict, jsval *val)
{
	int32_t propId = JSID_TO_INT(_id);
	S_SimpleNativeClass *cobj; JSGET_PTRSHELL(S_SimpleNativeClass, cobj, obj);
	if (!cobj) return JS_FALSE;
	switch(propId) {
	case kSomeField:
		do { uint32_t tmp; JS_ValueToECMAUint32(cx, *val, &tmp); cobj->setSomeField(tmp); } while (0);
		break;
	case kSomeOtherField:
		do { uint32_t tmp; JS_ValueToECMAUint32(cx, *val, &tmp); cobj->setSomeOtherField(tmp); } while (0);
		break;
	case kAnotherMoreComplexField:
		do {
			char *tmp = JS_EncodeString(cx, JSVAL_TO_STRING(*val));
			if (tmp) { cobj->setAnotherMoreComplexField(tmp); }
		} while (0);
		break;
	default:
		break;
	}
	return JS_TRUE;
}

void S_SimpleNativeClass::jsCreateClass(JSContext *cx, JSObject *globalObj, const char *name)
{
	jsClass = (JSClass *)calloc(1, sizeof(JSClass));
	jsClass->name = name;
	jsClass->addProperty = JS_PropertyStub;
	jsClass->delProperty = JS_PropertyStub;
	jsClass->getProperty = JS_PropertyStub;
	jsClass->setProperty = JS_StrictPropertyStub;
	jsClass->enumerate = JS_EnumerateStub;
	jsClass->resolve = JS_ResolveStub;
	jsClass->convert = JS_ConvertStub;
	jsClass->finalize = jsFinalize;
	jsClass->flags = JSCLASS_HAS_PRIVATE;
		static JSPropertySpec properties[] = {
			{"someField", kSomeField, JSPROP_PERMANENT | JSPROP_SHARED, S_SimpleNativeClass::jsPropertyGet, S_SimpleNativeClass::jsPropertySet},
			{"someOtherField", kSomeOtherField, JSPROP_PERMANENT | JSPROP_SHARED, S_SimpleNativeClass::jsPropertyGet, S_SimpleNativeClass::jsPropertySet},
			{"anotherMoreComplexField", kAnotherMoreComplexField, JSPROP_PERMANENT | JSPROP_SHARED, S_SimpleNativeClass::jsPropertyGet, S_SimpleNativeClass::jsPropertySet},
			{0, 0, 0, 0, 0}
		};

		static JSFunctionSpec funcs[] = {
			JS_FN("thisReturnsALongLong", S_SimpleNativeClass::jsthisReturnsALongLong, 0, JSPROP_PERMANENT | JSPROP_SHARED),
			JS_FN("receivesLongLong", S_SimpleNativeClass::jsreceivesLongLong, 1, JSPROP_PERMANENT | JSPROP_SHARED),
			JS_FN("returnsAString", S_SimpleNativeClass::jsreturnsAString, 0, JSPROP_PERMANENT | JSPROP_SHARED),
			JS_FN("returnsACString", S_SimpleNativeClass::jsreturnsACString, 0, JSPROP_PERMANENT | JSPROP_SHARED),
			JS_FN("doSomeProcessing", S_SimpleNativeClass::jsdoSomeProcessing, 2, JSPROP_PERMANENT | JSPROP_SHARED),
			JS_FS_END
		};

		static JSFunctionSpec st_funcs[] = {
			JS_FS_END
		};

	jsObject = JS_InitClass(cx,globalObj,NULL,jsClass,S_SimpleNativeClass::jsConstructor,0,properties,funcs,NULL,st_funcs);
}

JSBool S_SimpleNativeClass::jsthisReturnsALongLong(JSContext *cx, uint32_t argc, jsval *vp) {
	JSObject* obj = (JSObject *)JS_THIS_OBJECT(cx, vp);
	S_SimpleNativeClass* self = NULL; JSGET_PTRSHELL(S_SimpleNativeClass, self, obj);
	if (self == NULL) return JS_FALSE;
	if (argc == 0) {
		jsval *argv = JS_ARGV(cx, vp);
		long long ret = self->thisReturnsALongLong();
		do { jsval tmp; JS_NewNumberValue(cx, ret, &tmp); JS_SET_RVAL(cx, vp, tmp); } while (0);
		
		return JS_TRUE;
	}
	JS_SET_RVAL(cx, vp, JSVAL_TRUE);
	return JS_TRUE;
}
JSBool S_SimpleNativeClass::jsreceivesLongLong(JSContext *cx, uint32_t argc, jsval *vp) {
	JSObject* obj = (JSObject *)JS_THIS_OBJECT(cx, vp);
	S_SimpleNativeClass* self = NULL; JSGET_PTRSHELL(S_SimpleNativeClass, self, obj);
	if (self == NULL) return JS_FALSE;
	if (argc == 1) {
		jsval *argv = JS_ARGV(cx, vp);
		long long arg0 = argv[0].toNumber();
		self->receivesLongLong(arg0);
		
		JS_SET_RVAL(cx, vp, JSVAL_TRUE);
		return JS_TRUE;
	}
	JS_SET_RVAL(cx, vp, JSVAL_TRUE);
	return JS_TRUE;
}
JSBool S_SimpleNativeClass::jsreturnsAString(JSContext *cx, uint32_t argc, jsval *vp) {
	JSObject* obj = (JSObject *)JS_THIS_OBJECT(cx, vp);
	S_SimpleNativeClass* self = NULL; JSGET_PTRSHELL(S_SimpleNativeClass, self, obj);
	if (self == NULL) return JS_FALSE;
	if (argc == 0) {
		std::string ret = self->returnsAString();
		do { JSString *tmp = JS_NewStringCopyZ(cx, ret.c_str()); JS_SET_RVAL(cx, vp, STRING_TO_JSVAL(tmp)); } while (0);
		
		return JS_TRUE;
	}
	JS_SET_RVAL(cx, vp, JSVAL_TRUE);
	return JS_TRUE;
}
JSBool S_SimpleNativeClass::jsreturnsACString(JSContext *cx, uint32_t argc, jsval *vp) {
	JSObject* obj = (JSObject *)JS_THIS_OBJECT(cx, vp);
	S_SimpleNativeClass* self = NULL; JSGET_PTRSHELL(S_SimpleNativeClass, self, obj);
	if (self == NULL) return JS_FALSE;
	if (argc == 0) {
		const char* ret = self->returnsACString();
		if (ret == NULL) {
			JS_SET_RVAL(cx, vp, JSVAL_NULL);
			return JS_TRUE;
		}
		do { JSString *tmp = JS_NewStringCopyZ(cx, ret); JS_SET_RVAL(cx, vp, STRING_TO_JSVAL(tmp)); } while (0);
		
		return JS_TRUE;
	}
	JS_SET_RVAL(cx, vp, JSVAL_TRUE);
	return JS_TRUE;
}
JSBool S_SimpleNativeClass::jsdoSomeProcessing(JSContext *cx, uint32_t argc, jsval *vp) {
	JSObject* obj = (JSObject *)JS_THIS_OBJECT(cx, vp);
	S_SimpleNativeClass* self = NULL; JSGET_PTRSHELL(S_SimpleNativeClass, self, obj);
	if (self == NULL) return JS_FALSE;
	if (argc == 2) {
		jsval *argv = JS_ARGV(cx, vp);
		JSString *arg0 = JSVAL_TO_STRING(argv[0]);
		std::string narg0 = JS_EncodeString(cx, arg0);
		JSString *arg1 = JSVAL_TO_STRING(argv[1]);
		std::string narg1 = JS_EncodeString(cx, arg1);
		int ret = self->doSomeProcessing(narg0, narg1);
		do { jsval tmp; JS_NewNumberValue(cx, ret, &tmp); JS_SET_RVAL(cx, vp, tmp); } while (0);
		
		return JS_TRUE;
	}
	JS_SET_RVAL(cx, vp, JSVAL_TRUE);
	return JS_TRUE;
}

void register_enums_simple_native_generated(JSObject *global) {
	JSContext *cx = ScriptingCore::getInstance().getGlobalContext();
}
