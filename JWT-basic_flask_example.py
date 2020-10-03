from flask import Flask, request
from flask import jsonify
import datetime
from flask_jwt_extended import (
    JWTManager, jwt_required, create_access_token,
    get_jwt_identity, get_jwt_claims
)

app = Flask(__name__)
app.config['JWT_SECRET_KEY'] = "just a test"
jwt = JWTManager(app)


@jwt.user_claims_loader
def set_protected_data(identity):
    return {
        'hello': identity,
        'foo': ['test1', 'test2']
    }

@app.route('/ping')
def get_ping():
    return jsonify(ping="pong")

@app.route('/login', methods=['POST']) # Pending to change to DB
def login():
    if not request.is_json:
        return jsonify({"msg": "Missing JSON in request"}), 400

    username = request.json.get('username', None)
    passwd = request.json.get('password', None)

    if not username:
        return jsonify({"msg": "Missing username parameter"}), 400
    if not passwd:
        return jsonify({"msg": "Missing password parameter"}), 400

    if username != 'test' or passwd != 'test':
        return jsonify({"msg": "Bad username or password"}), 401

    access_token = create_access_token(identity=username)
    return jsonify(access_token=access_token), 200

@app.route('/get-identity', methods=['POST'])
@jwt_required
def validate():
    # Access the identity of the current user with get_jwt_identity
    current_user = get_jwt_identity()
    print (request.get_json())
    return jsonify(logged_in_as=current_user), 200

@app.route('/protected', methods=['POST'])
@jwt_required
def protected():
    claims = get_jwt_claims()
    return jsonify({
        'user': claims['hello'],
        'array_test': claims['foo']
    }), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0')