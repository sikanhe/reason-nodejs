[@bs.module "v8"] external cachedDataVersionTag: unit => int = "cachedDataVersion";

type heapSpaceStats = {
  [@bs.as "space_name"] space_name: string,
  [@bs.as "space_size"] space_size: int,
  [@bs.as "space_used_size"] space_used_size: int,
  [@bs.as "space_available_size"] space_available_size: int,
  [@bs.as "physical_space_size"] physical_space_size: int,
};

[@bs.module "v8"] external getHeapSpaceStatistics: unit => array(heapSpaceStats) = "getHeapSpaceStatistics";

[@bs.module "v8"] external getHeapSnapshot: unit => Stream.Readable.t(Buffer.t) = "getHeapSnapshot";

type heapStats = {
  [@bs.as "total_heap_size"] total_heap_size: int,
};

[@bs.module "v8"] external getHeapStatistics: unit => heapStats = "getHeapStatistics";
