#include "Test.h"

void Test::OnAttach() {
	CAPPU_LOG("Hello");
}

void Test::OnDetach() {
	CAPPU_LOG("Goodbye");
}

void Test::OnUpdate(float delta) {
	CAPPU_LOG("Test");
}

