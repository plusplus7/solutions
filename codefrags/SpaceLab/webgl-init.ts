import fs_simple from './shaders/fs_simple.glsl';
import vs_simple from './shaders/vs_simple.glsl';

export var canvas: HTMLCanvasElement = <HTMLCanvasElement> document.getElementById('my_Canvas');
export var gl: WebGLRenderingContext = <WebGLRenderingContext>canvas.getContext('experimental-webgl');

var simpleProgram = gl.createProgram();

function loadFragmentShaders(fs: string, program: WebGLProgram) {
    var fragShader = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fragShader, fs);
    gl.compileShader(fragShader);
    gl.attachShader(program, fragShader);
}

function loadVertexShaders(vs: string, program: WebGLProgram) {
    var vertShader = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vertShader, vs);
    gl.compileShader(vertShader);
    gl.attachShader(program, vertShader);
}

function prepareProgram(program: WebGLProgram) {
    gl.linkProgram(program);
    gl.useProgram(program);
}

loadFragmentShaders(fs_simple, simpleProgram);
loadVertexShaders(vs_simple, simpleProgram);
prepareProgram(simpleProgram);

export var SimpleProgram = simpleProgram;