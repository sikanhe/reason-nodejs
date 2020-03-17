[@bs.module "v8"] external cachedDataVersionTag: unit => int = "cachedDataVersion";

type heapSpaceStats = {
  [@bs.as "space_name"] space_name: string,
  [@bs.as "space_size"] space_size: int,
  [@bs.as "space_used_size"] space_used_size: int,
  [@bs.as "space_available_size"] space_available_size: int,
  [@bs.as "space_physical_size"] space_physical_size: int,
};

[@bs.module "v8"] external getHeapSpaceStatistics: unit => array(heapSpaceStats) = "getHeapSpaceStatistics";

[@bs.module "v8"] external getHeapSnapshot: unit => Stream.Readable.t(Buffer.t) = "getHeapSnapshot";

type heapStats = {
  [@bs.as "total_heap_size_executable"] total_heap_size_executable: int,
  [@bs.as "total_physical_size"] total_physical_size: int,
  [@bs.as "total_available_size"] total_available_size: int,
  [@bs.as "used_heap_space"] used_heap_space: int,
  [@bs.as "heap_size_limit"] heap_size_limit: int,
  [@bs.as "malloced_memory"] malloced_memory: int,
  [@bs.as "peak_malloced_memory"] peak_malloced_memory: int,
  [@bs.as "does_zap_garbage"] does_zap_garbage: int,
  [@bs.as "number_of_native_contexts"] number_of_native_contexts: int,
  [@bs.as "number_of_detached_contexts"] number_of_detached_contexts: int,
};

[@bs.module "v8"] external getHeapStatistics: unit => heapStats = "getHeapStatistics";

type heapCodeStats = {
  [@bs.as "code_and_metadata_size"] code_and_metadata_size: int,
  [@bs.as "bytecode_and_metadata_size"] bytecode_and_metadata_size: int,
  [@bs.as "external_script_source_size"] external_script_source_size: int,
};

[@bs.module "v8"] external getHeapCodeStatistics: unit => heapStats = "getHeapCodeStatistics";

[@bs.module "v8"] external writeHeapSnapshot: (string) => Js.Json.t = "writeHeapSnapshot";

[@bs.module "v8"] external serialize: 'a => Buffer.t = "serialize";
[@bs.module "v8"] external deserialize: Buffer.t => 'a = "deserialize";
