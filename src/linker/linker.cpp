#include "quark/linker/linker.h"

namespace quark::linker{

namespace {
    bool has_entry_attr(const ast::FuncStmt& func) {
        for (const auto& attr : func.attributes) {
            if (attr.name == "entry") return true;
        }
        return false;
    }
}

    const ast::FuncStmt* Linker::find_entry() {
        const ast::FuncStmt* fallback = nullptr;
        for (auto* mod : modules.ordered_modules()) {
            for (auto* stmt : mod->ast) {
                if (auto* func = std::get_if<ast::FuncStmt>(&stmt->kind)){
                    if (has_entry_attr(*func)) {
                        return func;
                    }
                    if (func->name == "main") {
                        fallback = func;
                    }
                }
            }
        }
        return fallback;
    }
    void Linker::validate() {
        if (!find_entry()) {
            utils::logger::fatal("entry point not found (add @entry or name it 'main')");
        }
    }
    Linker::Linker(modules::ModuleManager& m): modules(m){}
}