#include "il2cpp-config.h"
#include "icalls/mscorlib/System/Delegate.h"
#include "vm/Class.h"
#include "vm/Method.h"
#include "vm/Object.h"
#include "vm/Type.h"
#include "vm/Reflection.h"
#include "vm/Runtime.h"
#include "il2cpp-class-internals.h"
#include "il2cpp-object-internals.h"

namespace il2cpp
{
namespace icalls
{
namespace mscorlib
{
namespace System
{
    Il2CppDelegate * Delegate::CreateDelegate_internal(Il2CppReflectionType *__type, Il2CppObject *target, Il2CppReflectionMethod *info, bool throwOnBindFailure)
    {
        Il2CppClass *delegate_class = il2cpp::vm::Class::FromIl2CppType(__type->type);
        const MethodInfo *method = info->method;

        IL2CPP_ASSERT(delegate_class->parent == il2cpp_defaults.multicastdelegate_class);

        //if (mono_security_get_mode () == MONO_SECURITY_MODE_CORE_CLR) {
        //  if (!mono_security_core_clr_ensure_delegate_creation (method, throwOnBindFailure))
        //      return NULL;
        //}

        Il2CppObject* delegate = il2cpp::vm::Object::New(delegate_class);
        Il2CppMethodPointer func = method->methodPointer;

        il2cpp::vm::Type::ConstructDelegate((Il2CppDelegate*)delegate, target, func, method);

        return (Il2CppDelegate*)delegate;
    }

    void Delegate::SetMulticastInvoke(Il2CppDelegate * delegate)
    {
#if IL2CPP_TINY
        IL2CPP_NOT_IMPLEMENTED_ICALL(Delegate::SetMulticastInvoke);
#else
#endif
    }

    Il2CppMulticastDelegate* Delegate::AllocDelegateLike_internal(Il2CppDelegate* d)
    {
#if IL2CPP_TINY
        IL2CPP_NOT_IMPLEMENTED_ICALL(Delegate::AllocDelegateLike_internal);
        return NULL;
#else
        IL2CPP_ASSERT(d->object.klass->parent == il2cpp_defaults.multicastdelegate_class);

        Il2CppMulticastDelegate *ret = (Il2CppMulticastDelegate*)il2cpp::vm::Object::New(d->object.klass);

        Il2CppMethodPointer func = d->method_ptr;
        il2cpp::vm::Type::ConstructDelegate(&ret->delegate, NULL, func, d->method);

        return ret;
#endif
    }

    Il2CppReflectionMethod* Delegate::GetVirtualMethod_internal(Il2CppDelegate* _this)
    {
#if IL2CPP_TINY
        IL2CPP_NOT_IMPLEMENTED_ICALL(Delegate::GetVirtualMethod_internal);
        return NULL;
#else
        const MethodInfo* resolvedMethod = _this->target != NULL ? il2cpp::vm::Object::GetVirtualMethod(_this->target, _this->method) : _this->method;
        return il2cpp::vm::Reflection::GetMethodObject(resolvedMethod, NULL);
#endif
    }
} /* namespace System */
} /* namespace mscorlib */
} /* namespace icalls */
} /* namespace il2cpp */
