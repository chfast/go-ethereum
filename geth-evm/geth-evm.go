// Build as
// go build --buildmode c-shared -o geth-evm.so  ./geth-evm

package main

// #include "evmc.h"
//
// struct evmc_result geth_evm_execute(
//     struct evmc_instance* instance,
//     struct evmc_context* context,
//     int rev,
//     struct evmc_message* msg,
//     uint8_t* code,
//     size_t code_size
// );
import "C"

//export geth_evm_execute
func geth_evm_execute(instance *C.struct_evmc_instance,
	context *C.struct_evmc_context,
	rev C.int,
	msg *C.struct_evmc_message,
	code *C.uint8_t,
	codeSize C.size_t) C.struct_evmc_result {
	return C.struct_evmc_result{}
}

// The main function of the main package.
// This function is required for --buildmode=c-shared but not exported
// in the final shared library, so cannot be called.
func main() {
}
