#include <string.h>

#include "omrport.h"
#include "ModronAssertions.h"
/* OMR Imports */
#include "AllocateDescription.hpp"
#include "CollectorLanguageInterfaceImpl.hpp"
#include "Configuration.hpp"
#include "EnvironmentBase.hpp"
#include "GCExtensionsBase.hpp"
#include "GlobalCollector.hpp"
#include "ObjectAllocationModel.hpp"
#include "ObjectAllocationInterface.hpp"
#include "ObjectModel.hpp"
#include "omr.h"
#include "omrgc.h"
#include "omrgcstartup.hpp"
#include "omrvm.h"
#include "StartupManagerImpl.hpp"

extern "C" {
/**
 Allocate a single object.
 */
omrobjectptr_t
PypyAllocateObject(VMThread *vmThread, uintptr_t allocSize, uintptr_t allocateFlags)
{
	MM_EnvironmentBase *env = MM_EnvironmentBase::getEnvironment(vmThread->omrVMThread);

	MM_ObjectAllocationModel allocationModel(env, allocSize, allocatedFlags);
	omrobjectptr_t objectPtr = (omrobjectptr_t)OMR_GC_AllocateObject(omrVMThread, &allocationModel);
	Assert_MM_false(NULL == obj);

	return objectPtr;
}

}
