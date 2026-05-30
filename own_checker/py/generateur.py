from flask import Flask,  render_template, request, jsonify

app = Flask(__name__)

def load_file(file_name):
    data = None
    with open(file_name, 'r') as file:
        data = file.read()
    return data

@app.route('/')
def index():
    return load_file("templates/index.html")

@app.route('/generate/')
def pycall():
    content = request.args.get('content', 0, type=str)
    
    print("call_received",content)
    return jsonify(result="data from python")

if __name__ == '__main__':
  app.run(debug=True)