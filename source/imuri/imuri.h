#ifndef IMURI_IMURI_H
#define IMURI_IMURI_H

#include "access_control_services.h"
#include "administrative_services.h"
#include "data_flow_services.h"

class IMURI : public IAdministrativeServices, public IAccessControlServices, public IDataFlowServices {
};

#endif //IMURI_IMURI_H