import "./styles/styles.scss";

import { createApp } from 'vue';
import { store } from './scripts/store/store';

import App from './components/App.vue';

const app = createApp(App);

app.use(store);

app.mount('#app');
