import firebase from "firebase";

const firebaseApp = firebase.initializeApp({
	apiKey: "AIzaSyCZC5t4hkoRrDGK-oHKI9QFdzvzkwKLpJQ",
	authDomain: "todoapp01100.firebaseapp.com",
	projectId: "todoapp01100",
	storageBucket: "todoapp01100.appspot.com",
	messagingSenderId: "41375719933",
	appId: "1:41375719933:web:6cf2c42570112f827ab994",
	measurementId: "G-R3G1JT01C2",
});

const db = firebaseApp.firestore();

export { db };
