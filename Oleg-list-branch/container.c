#include "list.h"
#include "container.h"

ContMet list_m = {
	list_delete, list_iter_begin, list_iter_end,
	list_insertToBegin, list_insertToEnd,
	list_iter_prev, list_iter_next,
	list_insertTo, list_iter_get,
	list_iter_zeroEqual, list_swap
};
