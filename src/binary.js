
let test = {
  string: "string",

  bufferFromIntArray: Buffer.from([1, 2, 3, 4]),
  bufferFromStringArray: Buffer.from(["H", "E", "L", "L", "O"]),
  bufferFromString: Buffer.from("Hello").slice(),

  int8Array: new Int8Array(),
  uint8Array: new Uint8Array(),
  uint8ClampedArray: new Uint8ClampedArray(),

  int16Array: new Int16Array(),
  uint16Array: new Uint16Array(),

  int32Array: new Int32Array(),
  unit32Array: new Uint32Array(),
  float32Array: new Float32Array(),

  float64Array: new Float64Array(),

  dataView: new DataView(new ArrayBuffer()),
};

console.log(test);
console.log("\r\n");

Object.keys(test).forEach((key) => {
  let data = test[key];
  console.log(`data: ${ key }:
    typeof data - ${ typeof data }
    data.constructor.name - ${ data.constructor.name }
    data.toString() - ${ data.toString() }
    Object.prototype.toString.call(data) - ${ Object.prototype.toString.call(data) }
    Array.prototype.toString.call(data) - ${ Array.prototype.toString.call(data) }
    ArrayBuffer.isView(data) - ${ ArrayBuffer.isView(data) }
    Buffer.isBuffer(data) - ${ Buffer.isBuffer(data) }
    unsafeReflectConstructor(data) - ${ unsafeReflectConstructor(data) }
    reflect - ${ reflect(data) }
  `);

});

function unsafeReflectConstructor(data) {
  return (Object.prototype.toString.call(data)).slice(8, -1);
};

console.log(Object.prototype.toString.call([]));
console.log(Object.prototype.toString.call(3));
console.log(Object.prototype.toString.call(new Map()));

function reflect(data) {
  let str = Object.prototype.toString.call(data);
  return str.slice(8, str.length - 1);
};
