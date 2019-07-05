#include "evmc.h"

struct evmc_result geth_evm_execute(
    struct evmc_instance* instance,
    struct evmc_context* context,
    int rev,
    struct evmc_message* msg,
    uint8_t* code,
    size_t code_size
);

static void destroy(struct evmc_instance* vm)
{
    (void)vm;
}

static evmc_capabilities_flagset get_capabilities(struct evmc_instance* vm)
{
    (void)vm;
    return EVMC_CAPABILITY_EVM1;
}

struct evmc_instance* evmc_create_geth_evm()
{
    static struct evmc_instance instance = {
        .abi_version = EVMC_ABI_VERSION,
        .name = "geth-evm",
        .version = "TODO",
        .destroy = destroy,
        // We have to pointer to function here because in Go's //export there is not way to express
        // "const" and it also converts enums to GoUint32 type.
        .execute = (evmc_execute_fn)geth_evm_execute,
        .get_capabilities = get_capabilities,
        .set_option = NULL,
        .set_tracer = NULL,
    };
    return &instance;
}
