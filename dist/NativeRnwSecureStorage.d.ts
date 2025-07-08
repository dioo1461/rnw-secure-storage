import type { TurboModule } from 'react-native';
export interface Spec extends TurboModule {
    get: (key: string) => Promise<string | null>;
    set: (key: string, value: string) => Promise<void>;
    delete: (key: string) => Promise<void>;
}
declare const _default: Spec;
export default _default;
